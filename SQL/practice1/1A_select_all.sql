CREATE TABLE IF NOT EXISTS Clients (
ID INTEGER PRIMARY KEY AUTOINCREMENT,
FirstName TEXT NOT NULL,
SecondName TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS SomeTable (
ID INTEGER PRIMARY KEY AUTOINCREMENT,
FirstName TEXT NOT NULL,
SecondName TEXT NOT NULL
);

INSERT INTO Clients (FirstName, SecondName)
VALUES ('Михаил', 'Булгаков');

SELECT * FROM SomeTable;