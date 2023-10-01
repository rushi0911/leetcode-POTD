# Write your MySQL query statement below
SELECT Email from (
SELECT Email,COUNT(email) as cnt FROM
Person GROUP BY email HAVING cnt > 1
) as p WHERE cnt>1