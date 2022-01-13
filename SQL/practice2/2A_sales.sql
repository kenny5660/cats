CREATE TABLE IF NOT EXISTS Sales (
ID INTEGER PRIMARY KEY AUTOINCREMENT,
ProductName  TEXT NOT NULL,
QuantitySold INTEGER NOT NULL
);

INSERT INTO Sales (ProductName, QuantitySold) VALUES ('Молоко', 10);
INSERT INTO Sales (ProductName, QuantitySold) VALUES ('Хлеб', 25);
INSERT INTO Sales (ProductName, QuantitySold) VALUES ('Масло', 5);
INSERT INTO Sales (ProductName, QuantitySold) VALUES ('Сахар', 50);



SELECT * FROM Sales;

SELECT ProductName FROM Sales ORDER BY QuantitySold DESC LIMIT 2;

DROP TABLE Sales;