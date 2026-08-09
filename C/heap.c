#include <stdio.h>
#include <stdlib.h>
#define SQUARE(x) x * x


// 定义一个结构体，用于演示内存对齐
#pragma pack(push, 1)  // 保存当前对齐设置，并设置为1字节对齐（取消对齐）
struct MyStruct {
    char a;        // 占用1字节
    double b;      // 占用8字节（大多数平台上double占用8字节）
};                   // 结构体总大小：1 + 8 = 9字节（取消对齐后）
#pragma pack(pop)     // 恢复之前的对齐设置

// 对比：默认对齐的结构体
struct MyStructAligned {
    char a;        // 占用1字节
    double b;      // 占用8字节
};                   // 结构体总大小：16字节（1字节char + 7字节填充 + 8字节double）

int main() {

    
    struct MyStruct s;
    int *p = (int*)malloc(sizeof(int));
    if (p == NULL) return -1;

    *p = 42;
    printf("before free: %d\n", *p);   // 正常输出 42

    free(p);    // 释放内存，但 p 仍保存着之前的地址（野指针）
    
    p = NULL;
    // 错误：p 现在是野指针，但代码没有检查，继续使用
    // *p = 100;            // 未定义行为：可能写入了不属于程序的内存
    printf("after free: %d\n", SQUARE(2 + 3));   // 可能崩溃、输出错误值、或看似正常

    // 计算结构体的大小
    printf("Size of MyStruct: %zu bytes\n", sizeof(struct MyStruct));

    // 更危险：再次 free
    // free(p);          // 如果执行，double free 错误

    return 0;
}