SELECT ts.date,
(
  SELECT COUNT(*)
  FROM incident_table AS it
  INNER JOIN statuses AS ev ON (ev.id = it.status_type) WHERE 
  ev.label = "new" 
  AND it.id = ( 
                SELECT sit.id
                FROM incident_table AS sit 
                WHERE 
                sit.task_id = it.task_id
                AND date(sit.timestamp) <= ts.date
                		ORDER BY sit.timestamp DESC, sit.id DESC 
                LIMIT 1 
              ) 
) as number_of_new,
(SELECT COUNT(*)
FROM incident_table AS it
INNER JOIN statuses AS ev ON (ev.id = it.status_type) WHERE 
ev.label = "completed" 
AND it.id = ( 
SELECT sit.id
FROM incident_table AS sit 
WHERE 
sit.task_id = it.task_id
AND date(sit.timestamp) <= ts.date
		ORDER BY sit.timestamp DESC, sit.id DESC 
LIMIT 1 
) 
) as number_of_completed

 FROM 
(SELECT DISTINCT date(timestamp) AS date FROM incident_table
WHERE 
date(timestamp) > date((SELECT max(timestamp) FROM incident_table), '-30 day'))as ts
ORDER BY date;