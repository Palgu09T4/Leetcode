CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 declare m int;
set m=n-1;
    RETURN (
        /* Write your T-SQL query statement below. */
SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT m, 1

  );
END