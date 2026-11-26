/* =====================================================================
   DBMS LAB RECORD - ALL PROGRAMS
   Part A : Assignment 1 (SQL queries, Q1 - Q7)
   Part B : Assignment 2 (PL/SQL programs 8, 9, 10)
   Notes: typos from the PDF (ligature glitches like "dis-nct", "trunk",
   "accoun-ng") are fixed. Q1, Q6(c), Q7 use the student tables
   EMPLOYPEE / DEPARTMENT; the other queries use default EMP / DEPT.
   ===================================================================== */

/* #####################  PART A : SQL QUERIES  ##################### */

-- ---------------------------------------------------------------------
-- Q1 (a) Create tables and insert data
-- ---------------------------------------------------------------------
create table employpee(
  empno number(10), empname varchar2(20), job varchar2(20), mgr number(10),
  hiredate date, salary number(10), comm number(10), deptno number(10));

create table department(
  deptno number(10), dname varchar2(20), loc varchar2(20));

insert into employpee values(325,'smith','clerk',433,'11-jan-95',3500,1400,20);
insert into employpee values(825,'james','clerk',466,'02-aug-81',2975,null,20);
insert into employpee values(433,'james','analyst',825,'03-dec-89',3500,null,40);
insert into employpee values(466,'mike','president',null,'18-nov-97',7000,null,30);
insert into employpee values(889,'adams','manager',433,'23-may-87',3250,0,10);
insert into employpee values(435,'blake','analyst',889,'03-dec-89',4500,0,40);

insert into department values(10,'accounting','chicago');
insert into department values(20,'research','dallas');
insert into department values(30,'sales','new york');
insert into department values(40,'operations','boston');
insert into department values(50,'purchase','los angeles');

-- Q1 (b) Simple DQL
select * from employpee;
select * from department;
select empno, empname, job from employpee;
select deptno, dname from department;
select distinct job from employpee;

-- ---------------------------------------------------------------------
-- Q2 Operators (logical and set)
-- ---------------------------------------------------------------------
select empname from employpee where job='analyst' and salary>2000;
select empname, empno from employpee where comm is null;
select empname from employpee
  where job in ('clerk','analyst','manager') and salary>3000;
select empname from employpee
  where deptno in (10,20,40) or job in ('clerk','analyst');
select empname, employpee.deptno, dname
  from employpee, department
  where dname='research' and employpee.deptno=department.deptno;
select empname from employpee where upper(empname) like 'B%E';

-- On default EMP table
(select job from emp where deptno=10) intersect (select job from emp where deptno=20);
(select distinct job from emp where deptno=10) minus (select distinct job from emp where deptno!=10);
select ename, sal from emp where sal + sal*20/100 > 3000;
select ename from emp where mgr is null;

-- ---------------------------------------------------------------------
-- Q3 (a) Aggregate functions (default EMP / DEPT)
-- ---------------------------------------------------------------------
select count(*) from emp;
select count(empno) from emp, dept
  where dname='ACCOUNTING' and emp.deptno=dept.deptno;
select sum(sal) from emp;
select deptno, avg(sal), max(sal), min(sal) from emp group by deptno;
select deptno, avg(sal), max(sal), min(sal) from emp
  group by deptno having count(empno)>2;

-- Q3 (b) String and date functions
select substr('MUFFAKHAM JAH',5,3) from dual;
select next_day(sysdate,'friday') from dual;
select sysdate from dual;

-- Age (replace the date with your date of birth)
select months_between(sysdate,'17-jan-2001')*30  "days",
       months_between(sysdate,'17-jan-2001')     "months",
       months_between(sysdate,'17-jan-2001')/12  "year"
from dual;

select add_months(sysdate,-6) "6 months before" from dual;
select add_months(sysdate, 6) "6 months after"  from dual;

select ename from emp where to_char(hiredate,'mon')='jan';

select ename||' working as '||job||' joined company on '||
       to_char(hiredate,'ddth "of" month yyyy')||' and has a salary of '||sal
       "Employee details"
from emp;

select ename, (sal+nvl(comm,0))*12 "annual salary" from emp;

-- ---------------------------------------------------------------------
-- Q4 (a) Clauses
-- ---------------------------------------------------------------------
select job, count(empno) from emp group by job;
select job, sum(sal) from emp group by job having sum(sal)>5000;  -- use 50000 as per the question text
select empno, ename, deptno, sal from emp order by ename, deptno, sal;
select ename, sal*12 "annual salary" from emp order by sal desc;

-- Q4 (b) Subqueries
select ename from emp where sal=(select max(sal) from emp);
select ename from emp where sal>(select avg(sal) from emp);
select ename from emp where sal>any(select sal from emp where deptno=30);
select ename from emp
  where sal>all(select sal from emp, dept
                where dname='SALES' and emp.deptno=dept.deptno);
select ename from emp where mgr=(select empno from emp where ename='JAMES');
select ename from emp
  where job='MANAGER' and sal>=(select avg(sal) from emp);

-- ---------------------------------------------------------------------
-- Q5 (a) Joins
-- ---------------------------------------------------------------------
select empno, ename, dept.deptno, dname
  from emp full outer join dept on emp.deptno=dept.deptno;

select e.ename "employee", m.ename "manager"
  from emp e, emp m where e.mgr=m.empno;

select e.ename "employee", m.ename "manager", e.deptno "deptno"
  from emp e, emp m where e.mgr=m.empno and e.deptno=m.deptno;

select * from emp full  outer join dept on emp.deptno=dept.deptno;
select * from emp left  outer join dept on emp.deptno=dept.deptno;
select * from emp right outer join dept on emp.deptno=dept.deptno;

-- Q5 (b) Integrity constraints
create table cust_dtls(
  cust_no   number(10) primary key,
  cust_name varchar2(15) check (cust_name = upper(cust_name)),
  cust_city varchar2(15) check (cust_city like 'H%'));

alter table emp  add primary key(empno);
alter table emp  modify ename not null;
alter table emp  modify comm default 0;
alter table dept add primary key(deptno);
alter table emp  add foreign key(deptno) references dept;
alter table emp  add foreign key(mgr) references emp;

select owner, constraint_type, constraint_name, status
  from user_constraints where table_name='EMP';
select owner, constraint_type, constraint_name, status
  from user_constraints where table_name='DEPT';

alter table dept add unique(loc);
-- find the generated name, then drop it:
select constraint_name from user_constraints
  where table_name='DEPT' and constraint_type='U';
alter table dept drop constraint SYS_C0012111;   -- use your constraint name

select constraint_name, table_name, status, search_condition, constraint_type
  from user_constraints where table_name='CUST_DTLS';
alter table cust_dtls disable constraint SYS_C0012007;  -- the check on cust_name

-- ---------------------------------------------------------------------
-- Q6 (a) Views
-- ---------------------------------------------------------------------
create view ep_view as
  select ename, dname, job from emp, dept
  where dept.deptno=30 and emp.deptno=dept.deptno;
select * from ep_view;

-- Q6 (b) DDL
alter table dept add budget number(10);
alter table dept modify budget number(12);
alter table dept modify budget number(12) default 5000;
drop table employpee;     -- student-created table only (re-create it before Q6(c) if needed)

-- Q6 (c) DML (on student tables)
alter table department rename to dept_details;
delete from dept_details where loc='new york';
delete from employpee where salary < (select avg(salary) from employpee);
update dept_details set deptno=70, dname='distribution' where dname='sales';
update employpee set salary = salary*1.05
  where salary > (select avg(salary) from employpee);
update employpee set salary = case
    when salary>2500 then salary + salary*5/100
    else salary + salary*6/100
  end;

-- ---------------------------------------------------------------------
-- Q7 (a) TCL / DCL
-- ---------------------------------------------------------------------
rollback;
commit;
savepoint abc;

grant all on employpee to it19302;
grant select, insert on cust_dtls to it19302;
grant all on employpee to it19302 with grant option;
select * from it19302.employee;          -- run as the other user
revoke select on cust_dtls from it19302;
revoke all on cust_dtls from it19302;

-- Q7 (b) Table locking
lock table emp, dept in share mode;
rollback;     -- or commit; releases the locks
commit;


/* ###################  PART B : PL/SQL PROGRAMS  ################### */
SET SERVEROUTPUT ON;

-- =====================================================================
-- 8. Simple PL/SQL programs
-- =====================================================================

-- 8(i) Display a simple message
begin
  dbms_output.put_line('hello world');
end;
/

-- 8(ii) Addition of 3 numbers
declare
  n1 number := &n1;
  n2 number := &n2;
  n3 number := &n3;
  n4 number;
begin
  n4 := n1 + n2 + n3;
  dbms_output.put_line('the answer is '||n4);
end;
/

-- 8(iii) Armstrong number
declare
  n number := &n;
  s number := 0;
  t number := n;
begin
  while t > 0 loop
    s := s + power(mod(t,10),3);
    t := trunc(t/10);
  end loop;
  if s = n then
    dbms_output.put_line(n||' is armstrong');
  else
    dbms_output.put_line(n||' is not armstrong');
  end if;
end;
/

-- 8(iv) Factorial of a number
declare
  num       number;
  factorial number := 1;
  i         number := 1;
begin
  num := &num;
  while i <= num loop
    factorial := factorial * i;
    i := i + 1;
  end loop;
  dbms_output.put_line('Factorial of '||num||' is: '||factorial);
end;
/

-- 8(v) Even numbers from 1 to 50
declare
  n number(3) := 0;
begin
  while n < 50 loop
    n := n + 2;
    dbms_output.put_line(n);
  end loop;
end;
/

-- 8(vi) Sum of digits of a number
declare
  n    number(5) := &n;
  s    number := 0;
  r    number(2) := 0;
  temp number := n;
begin
  while n != 0 loop
    r := mod(n,10);
    s := s + r;
    n := trunc(n/10);
  end loop;
  dbms_output.put_line('sum of digits of '||temp||' is '||s);
end;
/

-- 8(vii) Raise salary by 5% if salary > 5000 (empno as input)
declare
  empid  emp.empno%type := &empid;
  oldsal emp.sal%type;
  newsal emp.sal%type;
begin
  select sal into oldsal from emp where empno = empid;
  dbms_output.put_line('old salary is '||oldsal);
  update emp set sal = sal*1.05 where empno = empid and sal > 5000;
  select sal into newsal from emp where empno = empid;
  dbms_output.put_line('new salary is '||newsal);
end;
/

-- =====================================================================
-- 9. Functions, procedures and packages
-- =====================================================================

-- 9(i) Function: number of employees under a manager
create or replace function f(mg in number) return number
as
  m number;
begin
  select count(empno) into m from emp where mgr = mg;
  return m;
end f;
/
select f(7698) from dual;

-- 9(ii) Procedure: reverse a string and check palindrome
create or replace procedure palindrome(str varchar2)
as
  s    varchar2(10);
  str1 varchar2(100) := '';
begin
  for i in reverse 1..length(str) loop
    s := substr(str,i,1);
    str1 := str1 || s;
  end loop;
  if str = str1 then
    dbms_output.put_line('it is a palindrome string');
  else
    dbms_output.put_line('it is not a palindrome string');
  end if;
end palindrome;
/
execute palindrome('madam');
execute palindrome('hello');

-- 9(iii) Procedure: total, max, min (and avg) salary of a department
create or replace procedure display_info(d in number)
is
  tot_sal number;
  tot_emp number;
  max_sal number;
  min_sal number;
  avg_sal number;
begin
  select sum(sal), count(empno), max(sal), min(sal), avg(sal)
    into tot_sal, tot_emp, max_sal, min_sal, avg_sal
    from emp where deptno = d;
  dbms_output.put_line('The Total Salary of the department '||d||' is '||tot_sal);
  dbms_output.put_line('The Total no. of employees in department '||d||' is '||tot_emp);
  dbms_output.put_line('The maximum Salary of the department '||d||' is '||max_sal);
  dbms_output.put_line('The minimum Salary of the department '||d||' is '||min_sal);
  dbms_output.put_line('The average Salary of the department '||d||' is '||avg_sal);
end display_info;
/
execute display_info(20);

-- 9 (package example, per the syntax given in the record)
create or replace package emp_pkg as
  function  f(mg in number) return number;
  procedure display_info(d in number);
end emp_pkg;
/
create or replace package body emp_pkg as
  function f(mg in number) return number is
    m number;
  begin
    select count(empno) into m from emp where mgr = mg;
    return m;
  end f;

  procedure display_info(d in number) is
    tot_sal number; tot_emp number; max_sal number; avg_sal number;
  begin
    select sum(sal), count(empno), max(sal), avg(sal)
      into tot_sal, tot_emp, max_sal, avg_sal
      from emp where deptno = d;
    dbms_output.put_line('Total: '||tot_sal||'  Employees: '||tot_emp||
                         '  Max: '||max_sal||'  Avg: '||avg_sal);
  end display_info;
end emp_pkg;
/

-- =====================================================================
-- 10. Triggers (security features)
-- =====================================================================

-- 10(i) Restrict access to EMP outside working hours
--       (blocks weekends, and anything before 8 AM or after 6 PM)
create or replace trigger t1
before delete or insert or update on emp
begin
  if to_char(sysdate,'dy','nls_date_language=english') in ('sat','sun') then
    raise_application_error(-20100,'cannot access emp table on weekends');
  elsif to_number(to_char(sysdate,'hh24')) < 8
     or to_number(to_char(sysdate,'hh24')) >= 18 then
    raise_application_error(-20100,'cannot access emp table after working hours');
  end if;
end t1;
/
delete from emp where ename = 'SMITH';

-- 10(ii) Restrict access to DEPT for a particular user
create or replace trigger scott_restr
before insert or update or delete on dept
begin
  if user = 'SCOTT' then          -- replace with the user to block, e.g. 'SYSTEM'
    raise_application_error(-20200,'cannot access database');
  end if;
end scott_restr;
/
delete from dept where deptno = 10;

-- 10(iii) Store deleted EMP rows in EMPDEL
create table empdel(
  empno number(10), ename varchar2(10), job varchar2(10), mgr number(10),
  hiredate date, sal number(10), comm number(10), deptno number(10),
  deldate date);

create or replace trigger emp_del
after delete on emp for each row
begin
  insert into empdel values
    (:old.empno, :old.ename, :old.job, :old.mgr, :old.hiredate,
     :old.sal, :old.comm, :old.deptno, sysdate);
end;
/
delete from emp where sal = 950;
select * from empdel;

-- List triggers on EMP
select owner, trigger_name, table_name, status
  from all_triggers where table_name = 'EMP';
