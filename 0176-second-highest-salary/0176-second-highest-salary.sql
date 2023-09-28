# Write your MySQL query statement below
# SELECT salary as SecondHighestSalary from (select salary from Employee 
# ORDER BY salary ASC) as t1
# LIMIT 1 OFFSET 1 

SELECT max(salary) as SecondHighestSalary 
from Employee 
where salary <> (SELECT max(salary) from Employee)