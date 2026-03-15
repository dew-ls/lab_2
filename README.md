## Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
```
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello, world!" << endl;
	return 0;
}
```
4. Добавьте этот файл в локальную копию репозитория.
```
git add .
```
5. Закоммитьте изменения с *осмысленным* сообщением.
```
git commit -m "First version of code."

[master 414fea5] First version of code.
 1 file changed, 104 insertions(+)
 create mode 100644 README.md
```
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
```
#include <iostream>

int main()
{
	char * name;
	std::cout << "Enter your name: " ; cin >> name;
	std::cout << "Hello world from " << name << endl;
	return 0;
}
```
7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
```
git commit -m "Second version of code."


[master 4b5a9f6] Second version of code.
 1 file changed, 47 insertions(+)
```
8. Запушьте изменения в удалёный репозиторий.
```
git push -u origin main

branch 'master' set up to track 'origin/master'.
objects: 15, done.
Counting objects: 100% (15/15), done.
Delta compression using up to 6 threads
Compressing objects: 100% (14/14), done.
Writing objects: 100% (15/15), 3.27 KiB | 3.27 MiB/s, done.
Total 15 (delta 5), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (5/5), done.
remote:
remote: Create a pull request for 'master' on GitHub by visiting:
remote:      https://github.com/dew-ls/lab_2/pull/new/master
remote:
To https://github.com/dew-ls/lab_2.git
 * [new branch]      master -> master
```
9. Проверьте, что история коммитов доступна в удалёный репозитории.

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.
```
git branch patch1
git checkout patch1
```
2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
```
#include <iostream>

int main()
{
	char * name;
	std::cout << "Enter your name: " ; std::cin >> name;
	std::cout << "Hello world from " << name << endl;
	return 0;
}
```
3. **commit**, **push** локальную ветку в удалённый репозиторий.
```
git commit -am "Third version of code."
git push -u origin patch1

objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 6 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 384 bytes | 384.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
remote:
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/dew-ls/lab_2/pull/new/patch1
remote:
To https://github.com/dew-ls/lab_2.git
 * [new branch]      patch1 -> patch1
```
4. Проверьте, что ветка `patch1` доступна в удалённом репозитории.
5. Создайте pull-request `patch1 -> master`.
6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
```
#include <iostream>

int main()
{
	char * name; // varible for user's name
	std::cout << "Enter your name: " ; std::cin >> name; // initialising name
	std::cout << "Hello world from " << name << endl; // output
	return 0;
}
```
7. **commit**, **push**.
```
git commit -am "Fourth version of code."
git push -u origin patch1

objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 6 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 384 bytes | 384.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
remote:
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/dew-ls/lab_2/pull/new/patch1
remote:
To https://github.com/dew-ls/lab_2.git
```
8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
```
git merge patch1
git branch -d patch1

Deleted branch patch1 (was 3ea47e1).
```
10. Локально выполните **pull**.
```
git pull

Already up to date.
```
11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.
```
git log --oneline

3ea47e1 Fourth version of code.
447abf7 Third version of code.
a4cb4da Second version of code.
a013b1e First version of code.
```
12. Удалите локальную ветку `patch1`.
```
git branch

* master
```
### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.
```
git branch patch2
git checkout patch2

Switched to branch 'patch2'
```
2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.
```
clang-format -i -style=Mozilla hello_world.cpp

#include <iostream>

int
main()
{
  char* name; // varible for user's name
  std::cout << "Enter your name: ";
  std::cin >> name;                                 // initialising name
  std::cout << "Hello world from " << name << endl; // output
  return 0;
}
```
3. **commit**, **push**, создайте pull-request `patch2 -> master`.
```
git commit -am "Fifth version of code."
git push -u oigin patch2

 1 file changed, 7 insertions(+), 5 deletions(-a
objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 6 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 419 bytes | 419.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dew-ls/lab_2.git
   3ea47e1..2b6243d  patch2 -> patch2
```
4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
```
git checkout master

Switched to branch 'master'
Your branch is up to date with 'oigin/master'.

#include <iostream>

int main()
{
	char * name; // переменная для имени пользователя
	std::cout << "Enter your name: " ; std::cin >> name; // инициализация переменной
	std::cout << "Hello world from " << name << endl; // вывод
	return 0;
}

git commit -am "Fifth version of code."
git push -u origin master

objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 6 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 474 bytes | 474.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dew-ls/lab_2.git
   3ea47e1..48ca6f5  master -> master
branch 'master' set up to track 'oigin/master'.
```
5. Убедитесь, что в pull-request появились *конфликты*.
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
```
git checkout master
git pull 

Already up to date.

git checkout patch2
git rebase master

auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 2b6243d... Fifth version of code.
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config advice.mergeConflict false"
Could not apply 2b6243d... Fifth version of code.
include <iostream>

int
main()
{
<<<<<<< HEAD
        char * name; // переменная для имени пользователя
        std::cout << "Enter your name: " ; std::cin >> name; // инициализация переменной
        std::cout << "Hello world from " << name << endl; // вывод
        return 0;
=======
  char* name; // varible for user's name
  std::cout << "Enter your name: ";
  std::cin >> name;                                 // initialising name
  std::cout << "Hello world from " << name << endl; // output
  return 0;
>>>>>>> 2b6243d (Fifth version of code.)
}

git add hello_world.cpp
git rebase --continue

[detached HEAD 2b6243d] Fifth version of code.
1 file changed, 7 insetrions(+), 5 delitions(-)
Successfully rebased and updated refs/heads/master
```
7. Сделайте *force push* в ветку `patch2`
```
git push -u origin patch2 -a

objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 6 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 427 bytes | 427.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/dew-ls/lab_2.git
 + 2b6243d...c678719 patch2 -> patch2 (forced update)
branch 'patch2' set up to track 'oigin/patch2'.
```
8. Убедитель, что в pull-request пропали конфликтны. 
9. Вмержите pull-request `patch2 -> master`.
```
git merge patch2

Updating 48ca6f5..c678719
Fast-forward
 hello_world.cpp | 12 +++++++-----
 1 file changed, 7 insertions(+), 5 deletions(-)
```
