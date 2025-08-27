# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary 
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1   -- OFFSET 1 → skip the first row, start from the second row
) AS SecondHighestSalary;
