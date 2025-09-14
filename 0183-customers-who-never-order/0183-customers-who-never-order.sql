# Write your MySQL query statement below
select name as Customers
from Customers
left join
Orders
on Customers.id=Orders.Customerid
where Orders.customerId is null;