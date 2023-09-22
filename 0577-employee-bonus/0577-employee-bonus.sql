# Write your MySQL query statement below
select e.name as name , b.bonus as bonus FROM
Employee e LEFT JOIN Bonus b ON e.empId = b.empId
WHERE bonus < 1000 OR bonus is NULL