DROP TABLE contacts;
DROP TABLE email;
DROP TABLE phones;

CREATE TABLE contacts (
ID INTEGER PRIMARY KEY,
name  TEXT
);

CREATE TABLE email (
address  TEXT,
contact_id  INTEGER REFERENCES contacts (ID)
);

CREATE TABLE phones (
number  TEXT,
contact_id  INTEGER REFERENCES contacts (ID)
);
