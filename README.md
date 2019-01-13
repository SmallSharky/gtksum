# Арифметическая игра

- Сложение случайных чисел
- Числа от -999 до 999
- Интерфейс на gtkmm

## Сборка

0.Идем в терминал

1.Переходим к папке с исходниками

`$ cd /path/to/sources`

2.Создаем подпапку build и переходим в нее

`$ mkdir build`

`$ cd build`

3.Собираем

`$ cmake ..`

`$ make`

`$ sudo make install`

4.Запускаем

`$ gtksum`

## Игровой процесс

0.Читаем выражение

1.Вычисляем результат

2.Вводим результат в специальное поле в нижней части окна

3.Нажимаем клавишу `Enter` на клавиатуре

4.В случае неудачи читаем правильный ответ

5.Возвращаемся к шагу 0 или закрываем основное окно