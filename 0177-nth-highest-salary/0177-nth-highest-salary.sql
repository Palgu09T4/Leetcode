CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select r.salary from
      (
        select distinct salary,dense_rank() over(order by salary desc) as rn
        from employee 
      )as r where r.rn=N
      
  );
END