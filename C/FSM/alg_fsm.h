#ifndef ALG_FSM_H
#define ALG_FSM_H
#include "stdio.h"
#include "stdint.h"

typedef enum 
{
    FSM_STATE_0 = 0,
    FSM_STATE_1,
    FSM_STATE_2
}FSM_STATE;

typedef struct
{
    uint32_t tim_count;
}Struct_State_Data;

typedef struct 
{
    uint8_t state_num;//状态数量
    uint8_t now_state;//当前状态

    Struct_State_Data now_state_data;//当前状态数据

    // void (*init)(void);
    // void (*set_state)(uint8_t state);
    // void (* callback_func)(void);
}FSM;

#endif
