# offset : 건너뛸 entry 개수
select (select DISTINCT salary 
from Employee order by salary desc limit 1 offset 1) as SecondHighestSalary ;