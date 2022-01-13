

SELECT Departments.Name,COUNT(Employees.FullName)  FROM Departments 
LEFT JOIN Employees ON Employees.DepartmentID = Departments.ID 
GROUP BY Departments.Name;

SELECT * FROM Departments 
LEFT JOIN Employees ON Employees.DepartmentID = Departments.ID;
