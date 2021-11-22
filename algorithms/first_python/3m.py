import sys

name = sys.stdin.readline()
name = name.strip("\n")
a = float(input())

str_sql = """SELECT
  id,
  SUM(product_price) AS revenue_by_user
FROM
  dataset.data_table
WHERE
  ab_test = '{0}'
GROUP BY
  id
HAVING
  revenue_by_user < {1:.2f}""".format(name,a)
print(str_sql)