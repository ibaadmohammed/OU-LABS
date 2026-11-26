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
