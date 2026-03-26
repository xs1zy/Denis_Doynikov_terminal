# Virtual Terminal (C++)

## Описание
Виртуальный терминал с собственной файловой системой.

## Команды
- help
- exit
- ls
- cd
- cat
- touch
- mkdir
- rm
- restore
- mv
- edit

## Архитектура
- Entry — базовый класс
- Directory — директория
- SingleLineFile — однострочный файл
- MultiLineFile — многострочный файл
- Terminal — логика терминала

## Особенности
- Полиморфизм через virtual методы
- Скрытие вместо удаления
- Дерево через parent

## Сборка
```bash
g++ -std=c++17 *.cpp -o terminal