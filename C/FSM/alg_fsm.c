#include "alg_fsm.h"

void Fsm_init(FSM *fsm, uint8_t now_state, uint8_t state_num) // 初始化
{
    fsm->state_num = state_num;
    fsm->now_state = now_state;
    fsm->now_state_data.tim_count = 0;
}

void Fsm_set_state(FSM *fsm, uint8_t state) // 设置状态
{
    fsm->now_state = state;
    fsm->now_state_data.tim_count = 0;
}

void Fsm_Callback(FSM *fsm) // 回调函数
{
    fsm->now_state_data.tim_count++;
    switch (fsm->now_state)
    {
    case 0:
    {
        if(fsm->now_state_data.tim_count >= 1000)
        {
            Fsm_set_state(fsm, 1);
        }
    }
    break;
    case 1:
    {
        if(fsm->now_state_data.tim_count >= 1000)
        {
            Fsm_set_state(fsm, 0);
        }
    }
    break;

    default:
        break;
    }
}

int main()
{
    FSM fsm;

    Fsm_init(&fsm, 0, 2);

    while(1)
    {
        Fsm_Callback(&fsm);
    }

    return 0;
}