using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

using static System.Math;

CultureInfo.DefaultThreadCurrentCulture = CultureInfo.InvariantCulture;

var data = File.ReadAllText("input.txt").Split(Environment.NewLine, StringSplitOptions.RemoveEmptyEntries).Skip(1).ToArray();

long[] sx = { 0L, 0L, 0L, 0L };
var sy = 0L;
var sxy = 0L;
var sx2y = 0L;

foreach (var item in data)
{
    var buff = item.Split(' ').Select(i => Convert.ToInt64(i)).ToArray();
    var x = buff[0];
    var y = buff[1];

    for (var i = 0; i < sx.Length; ++i)
        sx[i] += (long)Pow(x, i + 1);

    sy += y;
    sxy += x * y;
    sx2y += (long)Pow(x, 2) * y;
}

var n = (double)data.Count();
double[,] k =
{
    { sx[3], sx[2], sx[1], sx2y },
    { sx[2], sx[1], sx[0], sxy },
    { sx[1], sx[0], n, sy },
};

for (var i = 0; i < 2; ++i)
{
    for (var j = i + 1; j < 3; ++j)
    {
        var r = k[j, i] / k[i, i];
        for (var c = i; c < 4; ++c)
            k[j, c] -= r * k[i, c];
    }
}

for (var i = 2; i > 0; --i)
{
    for (var j = i - 1; j >= 0; --j)
    {
        var r = k[j, i] / k[i, i];
        for (var c = 3; c > j; --c)
            k[j, c] -= r * k[i, c];
    }
}

List<string> ans = new(3);
for (var i = 0; i < 3; ++i)
    ans.Add((k[i, 3] / k[i, i]).ToString("F6"));

File.WriteAllText("output.txt", string.Join(' ', ans));
