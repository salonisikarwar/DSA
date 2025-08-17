# Write your MySQL query statement below
SELECT product_id ,year as first_year ,quantity , price
FROM  Sales
WHERE(product_id  , year) IN(Select product_id ,  min(year) as f_year FROM Sales
GROUP BY  Product_id)
