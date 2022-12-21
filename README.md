# TODO-List
TODO List application.
EN
Possibilities:
- Components of the task: title, description, creation date, category, progress status
- Editing/adding/viewing a task
- View a list of current tasks with the ability to filter by a given predicate

Commands:
1) add - add a new task. Arguments can consist of several words separated by a space,
so each in separate quotes. The date format is "%Y-%m-%d %H:%M" (example 2020-12-12 00:00).
The date cannot be less than 1970-01-01 07:00
Adding tasks with the same name is prohibited.
Format: add "task name" "description" "date" "category"
2) done - mark the task as completed. For this command, the argument is written without quotes
through the gap.
Format: done task name
3) update - update the task. For this command, the argument is written without quotes, separated by a space.
Format: update task name
4) delete - delete a task. For this command, the argument is written without quotes, separated by a space.
Format: delete task name
5) select - filter the list of tasks by a certain criterion.
Command format: select * where {predicate}
Criteria format: date < "2020-12-12 00:00" and category="cat1" and status="on" and description like "text"
select *(or select * where{}) - display all tasks. Several criteria are written with and.
Available date operators: <,<=,=,>=,<. For the title, category, and description, the = or like operators.
The like operator checks for the presence of the specified substring in a field. For status, only the = operator is possible.
The status can be either done or unfinished.
All spaces are respected as in the example:
select * where {status = "unfinished" and date < "2013-10-01 00:00" and category like "2"}

RU
Приложение TODO List.

Возможности:
- Составляющие задачи: заголовок, описание, дата создания, категория, статус выполнения
- Редактирование/добавление/просмотр задачи
- Просмотр списка текущих задач с возможностью отфильтровать по заданному предикату

Команды:
1) add - добавить новую задачу. Аргументы могут состоять из нескольких слов через пробел, 
поэтому каждый в отдельных кавычках. Формат даты "%Y-%m-%d %H:%M"(пример 2020-12-12 00:00).
Дата не может быть меньше  1970-01-01 07:00
Добавление задач с одинаковым названием запрещено.
	Формат: add "название задачи" "описание" "дата" "категория"
2) done - отметить задачу как выполненную. Для этой команды аргумент пишется без кавычек
через пробел.
	Формат: done название задачи
3) update - обновить задачу. Для этой команды аргумент пишется без кавычек через пробел.
	Формат: update название задачи
4) delete - удалить задачу. Для этой команды аргумент пишется без кавычек через пробел.
	Формат: delete название задачи
5) select - отфильтровать список задач по определенному критерию.  
	Формат команды: select * where {predicate}
	Формат критерия:  date < "2020-12-12 00:00" and category="cat1" and status="on" and description like "text"
select *(или select * where{}) - вывод всех задач. Несколько критериев пишутся через and. 
Доступные операторы для даты: <,<=,=,>=,<. Для названия, категории и описания операторы = или like. 
Оператор like проверяет наличие указанной подстроки в поле. Для статуса возможен только оператор =.
Статус может быть равен done или unfinished.
Все пробелы соблюдаются как в примере:
	select * where {status = "unfinished" and date < "2013-10-01 00:00" and category like "2"}
