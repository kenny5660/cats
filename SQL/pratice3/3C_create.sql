
CREATE TABLE IF NOT EXISTS Sales (
ID INTEGER PRIMARY KEY AUTOINCREMENT,
Note  TEXT NOT NULL UNIQUE,
TimeOfCreation DATETIME NOT NULL,
ProgressMade REAL CHECK(ProgressMade>=0 AND ProgressMade<=1) DEFAULT 0, 
Status TEXT CHECK(Status IN ('started', 'accepted', 'canceled')) DEFAULT 'started'
);
