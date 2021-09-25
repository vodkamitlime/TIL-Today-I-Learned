join


SELECT i.name, i.datetime
from animal_ins as i
left join animal_outs as o
on i.animal_id = o.animal_id
where o.animal_id is null
order by i.datetime
limit 3

datetime


SELECT animal_id, name, date_format(datetime,'%Y-%m-%d')
from animal_ins
order by animal_id


SELECT animal_type, ifnull(name, 'No name'), sex_upon_intake
from animal_ins
order by animal_id