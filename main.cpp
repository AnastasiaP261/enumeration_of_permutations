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
//                    print_list(list);
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


/*
void rec_alg(int *p, int step)
{

    p[step] = step + 1;
    for (int i = 0; i < step + 1; i++)
    {
    }
}

int main()
{
    int p[N];
    int step = 1; // номер перестановки
    p[0] = 1;

    rec_alg(p, step);
}
*/
