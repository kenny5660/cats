CREATE TABLE IF NOT EXISTS Animals (
ID INTEGER PRIMARY KEY AUTOINCREMENT,
Sex   TEXT
);

INSERT INTO Animals (Sex) VALUES ('male');
INSERT INTO Animals (Sex) VALUES ('female');
INSERT INTO Animals (Sex) VALUES ('male');
INSERT INTO Animals (Sex) VALUES ('male');
INSERT INTO Animals (Sex) VALUES ('male');
INSERT INTO Animals (Sex) VALUES (NULL);
INSERT INTO Animals (Sex) VALUES ('female');
INSERT INTO Animals (Sex) VALUES ('female');
INSERT INTO Animals (Sex) VALUES ('female');
INSERT INTO Animals (Sex) VALUES (NULL);
INSERT INTO Animals (Sex) VALUES ('fg');
INSERT INTO Animals (Sex) VALUES ('gf');

SELECT * FROM Animals;

UPDATE Animals
SET Sex =  CASE WHEN Sex = 'male' THEN 'm' ELSE CASE WHEN Sex = 'female' THEN 'w' ELSE 'unknown' END END
WHERE Sex NOT NULL;

SELECT * FROM Animals;


DROP TABLE Animals;