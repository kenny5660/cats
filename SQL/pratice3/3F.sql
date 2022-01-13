

SELECT * FROM incident_table
INNER JOIN statuses ON incident_table.status_type = statuses.id
ORDER BY timestamp;

SELECT DATE(timestamp), SUM(case when statuses.label  = 'new' Then 1 else 0 end) as number_of_new, SUM(case when statuses.label  = 'completed' Then 1 else 0 end) as number_of_completed 
from (SELECT *,MAX(incident_table.id) FROM incident_table
               GROUP BY task_id,timestamp) as incident_table_2
INNER JOIN statuses ON incident_table_2.status_type = statuses.id 
WHERE timestamp >= date((SELECT MAX(timestamp) FROM incident_table), '-31 day')
GROUP BY DATE(timestamp);

WITH RECURSIVE dates(date) AS (
  VALUES(date((SELECT MAX(timestamp) FROM incident_table), '-31 day'))
  UNION ALL
  SELECT date(date, '+1 day')
  FROM dates
  WHERE date < date((SELECT MAX(timestamp) FROM incident_table))
)
SELECT date, SUM(case when statuses.label  = 'new' Then 1 else 0 end) as number_of_new, SUM(case when statuses.label  = 'completed' Then 1 else 0 end) as number_of_completed   FROM dates
LEFT JOIN 
    (SELECT *,MAX(incident_table.id) FROM incident_table INNER JOIN statuses ON incident_table.status_type = statuses.id GROUP BY timestamp) as incident_table_2
    ON date(incident_table_2.timestamp) = dates.date
LEFT JOIN statuses ON incident_table_2.status_type = statuses.id
GROUP BY date
ORDER BY date;

