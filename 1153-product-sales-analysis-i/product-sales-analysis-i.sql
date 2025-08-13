# Write your MySQL query statement below
SELECT p.product_name , s.year,s.price
 FROM Sales AS s
Left JOIN product AS p 
ON p.product_id  = s.product_id;
 
