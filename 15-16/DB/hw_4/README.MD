Домашнее задание №4. Язык запросов SQL.

В данном ДЗ вам предлагается составить несколько запросов к базе данных ресурса http://stackoverflow.com
Для выполнения запросов необходимо будет воспользоваться формой по адресу: https://data.stackexchange.com/stackoverflow/query/new
Для начала изучите сам ресурс stackoverlow и схему БД, к которой предоставлен доступ по упомянутой выше веб-форме.
Затем приступайте к написанию самих запросов.
В качестве результата ДЗ от вас требуется текстовый файл с расширением 'sql', содержащий написанные вами запросы.

Стоит отметить, что на сервере stackoverflow используется база данных Microsoft SQL Server и соответствующий диалект языка SQL(Transact-SQL).
При этом запросы можно писать на стандартизированном подмножестве языка SQL, о котором было рассказано на лекциях.
Одно полезное расширение, реализованное в MSSQL - это ограничение размера возвращаемой выборки.
Для того чтобы получить только первые n строк из результата запроса необходимо написать `top n` после ключевого слова `select`.
Например, следующий запрос вернёт не более чем 100 кортежей с Id пользователей из таблицы Users:

     select top 100 Id from Users

Одно замечание о схеме БД http://stackoverflow.com: в таблице Posts нас будут интересовать только строки со значением 
атрибута PostTypeId = 1 (вопросы) или PostTypeId = 2(ответы на вопросы).

Список запросов, которые Вам требуется написать:
1. Имена всех пользователей.
2. Заголовок, текст и имя создателя для 100 последних созданных вопросов.
3. Количество зарегистрированных пользователей, вопросов, ответов и тэгов.
4. Имена и места проживания(Location) пользователей, зарегистрированных в 2015 году, старше 25 лет.
5. Количество пользователей, зарегистрированных в 2015 году, старше 25 лет.
6. Количество пользователей, у которых в качестве места проживания указана Germany.
7. Места проживания и количество пользователей, указавших соответствующее место проживания в своём профиле.
8. Первых 10 пользователей с максимальной репутацией, а также количество вопросов, созданных ими.
9. Всех пользователей, задавших не менее трёх вопросов с тэгом 'sql' и ответивших не менее чем на 10 вопросов с тэгом 'java'.
10. Все пары пользователей, таких что каждый из двух оставил хотя бы один комментарий под некоторым ответом другого пользователя.
11. Количество вопросов, в которых выбранный ответ содержит в два или более раза меньше комментариев, чем некоторый другой ответ на этот же вопрос.
12. Список всех вопросов с самым комментируемым ответом на данный вопрос.
13. Найдите всех пользователей, которые либо непосредственно отвечали на вопросы 
    либо оставляли комментарии(как комментарии к самому вопросу, так и комментарии к некоторому из ответов на вопрос)
    к вопросам, помеченных хотя бы 2 из 10 самых часто используемых в вопросах тэгов.

Примечание: если ваш запрос является корректным, но не успевает исполнится на сервере до истечения таймаута, то он всё равно засчитывается как правильный
в рамках данного ДЗ.

Результаты ДЗ необходимо отправить на электронный адрес iu.biryukov+itmo@gmail.com до
23:59 13 ноября. Обязательно укажите в письме ваши данные: ФИО, группу.  Баллы по
заданиям, отправленным после срока сдачи будут засчитаны только на 50%.  Также ДЗ можно
сдавать на второй паре по субботам.

NB. Обратите внимание, что на следующей неделе возможно будет выслано ещё одно ДЗ,
срок выполнения которого снова могут пересекаться с данным ДЗ.
