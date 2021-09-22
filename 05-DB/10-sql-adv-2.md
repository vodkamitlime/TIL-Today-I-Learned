join

-- 코드를 입력하세요
SELECT i.name, i.datetime
from animal_ins as i
left join animal_outs as o
on i.animal_id = o.animal_id
where o.animal_id is null
order by i.datetime
limit 3

datetime

-- 코드를 입력하세요
SELECT animal_id, name, date_format(datetime,'%Y-%m-%d')
from animal_ins
order by animal_id