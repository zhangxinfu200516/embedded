## 基础核心概念
### 1、RTOS基本概念
轻量级的实时操作系统、适用于微控制器/小型嵌入式系统设计
#### 任务概念
- 具备自己的栈空间 + 上下文 
- 任务内死循环
### 2、任务创建与管理
- 动态创建函数
```
BaseType_t xTaskCreate(
    TaskFunction_t pvTaskCode,       // 任务函数指针
    const char * const pcName,       // 任务名称
    uint16_t usStackDepth,           // 栈深度(字)
    void *pvParameters,              // 传递给任务的参数
    UBaseType_t uxPriority,          // 任务优先级
    TaskHandle_t *pxCreatedTask      // 任务句柄
);

作者：嵌入式求职之路
链接：https://www.nowcoder.com/discuss/662413234351112192
来源：牛客网
```
#### 任务状态及切换
- 任务状态：运行态、就绪态、阻塞态（等待事件、osdelay）、挂起态（通过API函数挂起与解挂）
- 状态转换：只有就绪态才能转换为运行态，挂起态与阻塞态必须先转化为就绪态后，才能进一步转换为运行态。
#### 任务优先级管理
### 3、任务调度与同步
#### 调度算法
- FreeRTOS默认使用抢占式优先级调度（高优先级任务可以抢占低优先级任务）
- 同优先级任务：使用时间片轮转调度。就是一个时间片执行A任务，这个时间片时间到了，换同优先级的B任务执行。
```
// 启动调度器
vTaskStartScheduler();
```
#### 任务延时
```
// 绝对延时(阻塞指定时钟节拍数)
void vTaskDelay(TickType_t xTicksToDelay);
 
// 相对延时(保证任务间隔固定)
void vTaskDelayUntil(
    TickType_t *pxPreviousWakeTime,  // 上次唤醒时间
    TickType_t xTimeIncrement        // 增量时间
);
```
#### 任务同步与通讯
- 信号量(Semaphore)：控制资源访问
- 互斥量(Mutex)：带优先级继承的信号量
- 消息队列(Queue)：任务间数据传递
- 事件组(Event Group)：多事件等待
- 任务通知(Task Notification)：轻量级通信机制
#### 空闲任务
- FreeRTOS程序在任意时刻，必须至少有一个任务处于运行状态
- Idle任务主要用于资源回收清理工作
### 4、内存管理与栈溢出检测
#### 内存分配方案
- 堆1(heap_1)：最简单的分配方案，不支持释放
- 堆2(heap_2)：支持释放，但可能产生碎片
- 堆3(heap_3)：使用标准库malloc/free
- 堆4(heap_4)：支持合并相邻空闲块
- 堆5(heap_5)：类似堆4，但支持跨多个内存区域
#### 栈溢出检测
- 栈溢出钩子函数
```
void vApplicationStackOverflowHook(
    TaskHandle_t xTask,
    char *pcTaskName
) {
    // 栈溢出处理
    printf("栈溢出: 任务名 = %s\r\n", pcTaskName);
    // 系统复位或其他处理
    NVIC_SystemReset();
}
```
- 栈剩余空间检测函数