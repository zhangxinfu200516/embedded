#include "stdio.h"
int c = 0;
// 指针函数
int *p(int *x, int *y)
{
    return (*x > *y) ? x : y;
}
// 函数指针
int (*q)(int *, int *, int *);
int add(int *x, int *y, int *z)
{
    *z = *x + *y;
    // return *z;
}
//
int main()
{
    int x = 10, y = 5;
    int *a = p(&x, &y);
    printf("%d\n", *a);

    q = add;
    q(&x, &y, &c);
    printf("%d\n", c);

    // 数组指针、指针数组
    int arr[3] = {0, 1, 2};
    int arr_1[3] = {3, 4, 5};

    int (*arr_A[2])[3] = {&arr, &arr_1};// 数组指针，每一个元素都是一个指向数组的指针
    int (*arr_C)[3]=&arr;

    int *arr_B[2] = {arr, arr_1};// 指针数组，每一个元素都一个向一个变量地址的指针

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", (*arr_A[0])[i]);
    }
    printf("指针数组\n");
    for (int i = 0; i < 3; i++)
    {
        // printf("%d\n", (*arr_A[0])[i]);
    }
    return 0;
}
