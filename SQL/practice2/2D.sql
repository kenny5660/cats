CREATE TABLE IF NOT EXISTS Employees  (
ID INTEGER PRIMARY KEY AUTOINCREMENT,
FullName   TEXT NOT NULL,
Age  INTEGER NOT NULL,
Sex  TEXT NOT NULL
);

INSERT INTO Employees (FullName,Age,Sex) VALUES ('Петя', 10,'male');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Петя', 50,'male');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Петя', 70,'male');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Петя', 35,'male');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Петя', 40,'male');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Люся', 10,'female');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Люся', 35,'female');
INSERT INTO Employees (FullName,Age,Sex) VALUES ('Люся', 50,'female');

SELECT * FROM Employees;

SELECT * FROM Employees
WHERE AGE >= 35 AND AGE <=70 AND Sex = 'male';



DROP TABLE Employees;