# Write your MySQL query statement below
SELECT (
    SELECT salary 
    FROM (
        SELECT salary,
            DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
        FROM Employee
        WHERE salary IS NOT NULL
    ) t
    WHERE rnk = 2
    LIMIT 1
) as SecondHighestSalary