SELECT Employees.FullName, ROUND(SUM(Salary*SalaryPercentage), 0) as SalaryReal FROM Salaries
INNER JOIN Employees ON Employees.ID = Salaries.EmployeeID
INNER JOIN Positions ON Positions.ID = Salaries.PositionID
GROUP BY EmployeeID
HAVING  SalaryReal < (SELECT AVG(SalaryReal) FROM(
                                    SELECT SUM(Salary*SalaryPercentage) as SalaryReal FROM Salaries
                                    INNER JOIN Employees ON Employees.ID = Salaries.EmployeeID
                                    INNER JOIN Positions ON Positions.ID = Salaries.PositionID
                                    GROUP BY EmployeeID))
ORDER BY SalaryReal DESC;




