*Данная программа выполнена в качестве лабораторной работы по курсу "Методы комбинаторных вычислений" в университете.*

## Задание на лабораторную работу
Перечислить все перестановки первых 5-ти натуральных чисел в порядке минимального изменения, используя рекурсивный алгоритм транспозиции смежных элементов.

## Описание комбинаторного алгоритма
В общем случае такая транспозитивная последовательность перестановок легко выстраивается по следующему рекурсивному правилу. Пусть имеется последовательность (n−1)! перестановок из (n−1) элементов, в которой соседние перестановки отличаются транспозицией только двух смежных элементов. Состав каждой из них можно расширить до перестановки из n элементов, добавляя элемент n последовательно на каждую позицию, справа налево для нечетных и слева направо для четных по номеру перестановок из (n−1) элементов. Порядок порождаемых таким способом перестановок элементов множества натуральных чисел {1,2,3} показан на следующей диаграмме:  

![здесь должна была быть картинка но ее нет :(](https://i.ibb.co/85gNgYd/a.png)  

Из этой диаграммы должно быть понятно, что сначала добавление справа налево элемента 2 в тривиальную одноэлементную перестановку (1) порождает последовательность перестановок из двух элементов:  
__*ПT2: (12); (21).*__  
Затем в каждую из этих перестановок нужно поочередно добавить элемент 3, соответственно, справа налево и слева направо, с учетом четности их порядковых номеров. Это дает в итоге требуемую последовательность перестановок трех элементов:  
__*ПT3: (123); (132); (312); (321); (231); (213).*__

## Описание алгоритма программы
Для реализации исходного задания была написана программа на языке С++.  
Алгоритм транспозиции смежных элементов осуществляется посредством функции  
`void rec_alg(vector<int> *list, int step, int level)`.  
Функция работает рекурсивно. Изначально на вход функции подается вектор __list__ с уже лажащей внутри начальной единицей, а таже переменные __step__ и __level__, номер перестановки и уровень дерева соответственно. В нашем случае __N=5__, что было определено в начале программы.  
Далее в зависимости от номера перестановки новое число добавляется к имеющимся справа или слева, а затем двигается в этом направлении по вектору. 

## Листинг
```c++
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "vector"

using namespace std;

#define N 5

void print_list(vector<int> *list) {
    if (list->size() == N) {
        for (int n: *list) {
            cout << n;
        }
        cout << " " << endl;
    }
}

void rec_alg(vector<int> *list, int step, int level){
    print_list(list);
    if (list->size() < N) {
        if (step % 2 == 1) {
            list->push_back(level);

            rec_alg(list, 1, level+1);
            if (list->size() >= 2) {
                for (int i = list->size() - 1; i > 0; i--) {
                    iter_swap(list->begin() + i, list->begin() + i - 1);
                    rec_alg(list, i+1, level+1);
                }
            }
            list->erase(list->begin() + 0);

        } else {
            list->insert(list->begin() + 0, level);

            rec_alg(list, 0, level+1);
            if (list->size() > 2) {
                for(int i = 0; i < list->size() - 1; i++) {
                    iter_swap(list->begin() + i, list->begin() + i + 1);
                    rec_alg(list, i+1, level+1);
                }
            }
            list->erase(list->begin() + list->size() - 1);
            print_list(list);
        }
    }
}

int main()
{
    vector<int> list = {1};
    int step = 1; // номер перестановки
    int level = 1; // номер этажа дерева

    rec_alg(&list, step, level+1);
}
```