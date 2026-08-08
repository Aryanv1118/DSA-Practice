CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        SELECT salary
        FROM(
            SELECT salary,
                Dense_rank() OVER(ORDER BY salary DESC) AS rnk
            FROM Employee
            WHERE salary IS NOT NULL
        ) t
        WHERE rnk = N
        LIMIT 1
  );
END
