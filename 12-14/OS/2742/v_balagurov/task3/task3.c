#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define V 7 //Количество вершин графа
#define E 11 //количество рёбер графа

int graph[E][2] = {//Сам граф описанный, как таблица рёбер. Вершины пронумерованны слава направо от 0 до 1.
    {0, 1}, // a
    {0, 4}, // b
    {0, 5}, // c
    {1, 2}, // d
    {2, 3}, // e
    {2, 4}, // f
    {1, 3}, // g
    {3, 4}, // h
    {4, 5}, // i
    {5, 6}, // j
    {5, 6}  // k
};

pid_t pids[E]; //Массив идентификаторов процессов, очевидно, что процессов будет по колличеству рёбер графа.

int v, i;

int main()
{
    for (v = 0; v < V; v++)//Проходим по всем вершинам слева направо
    {
       for (i = 0; i < E; i++)//Проверяем все рёбра, чтобы завершить все процессы, входящие в эту вершину
            if (graph[i][1] == v)//Если какое-то ребро заканчивается в текущей вершине, то
            {
                waitpid(pids[i], NULL, 0);//Ожидаем завершения процесса, поскольку процессы пронумерованы как рёбра в графе, то можно так обращаться к массиву идентификаторов
                printf("Join process %c\n", (char) (i + 65));//Выведем сообщение, что совместились с нужным процессом.
            }

        for (i = 0; i < E; i++)//Завершив все процессы входящие в вершину, теперь можно из этой вершины размножить процессы. Проходим по всем рёбрам
            if (graph[i][0] == v)//Если некоторый процесс начинается в текущей вершине
            {
                pids[i] = fork();//Начинаем его
                if (pids[i] == 0)//Если мы в дочернем процессе, то выполним небольшую задачу, результат форка не будет нулём для не дочерненго родительского процесса 
                {
                    printf("Start process %c, pid = %d\n", (char) (i + 65), getpid());//Маркерное сообщение о начале процесса
                    sleep((graph[i][1] - graph[i][0])*2);//Приостановим процесс на колличество секунд, равное удроенной разности индексов вершин
                    printf("Stop process %c\n", (char) (i + 65));//Маркерное сообщение о конце процесса
                    return 0;//И завершаем процесс
                }
            }
    }
    return 0;
}


