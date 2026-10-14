// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 14/14)
// FUN_002655b0 @ 0x002655b0
class Task_2655b0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

class TaskQueue {
public:
    char pad0[8];
    int busy;                 // 0x08
    char pad1[8];
    char *ring1Cur;           // 0x14
    char *ring1End;           // 0x18
    char *ring1Base;          // 0x1c
    char *ring1Limit;         // 0x20
    char pad2[4];
    Task_2655b0 **ring2Cur;          // 0x28
    Task_2655b0 **ring2End;          // 0x2c
    Task_2655b0 **ring2Base;         // 0x30
    Task_2655b0 **ring2Limit;        // 0x34
    void FUN_00264d20();
    void FUN_002655b0();
};

static int Ring1Count(char *cur, char *end, char *base, char *limit)
{
    if (cur <= end)
        return (end - cur) >> 3;
    return ((end - base) >> 3) + ((limit - cur) >> 3);
}

static int Ring2Count(Task_2655b0 **cur, Task_2655b0 **end, Task_2655b0 **base, Task_2655b0 **limit)
{
    if (cur <= end)
        return (end - cur);
    return (end - base) + (limit - cur);
}

void TaskQueue::FUN_002655b0()
{
    if (Ring1Count(ring1Cur, ring1End, ring1Base, ring1Limit) != 0 || busy != 0)
        FUN_00264d20();
    while (Ring2Count(ring2Cur, ring2End, ring2Base, ring2Limit) != 0) {
        Task_2655b0 *t = *ring2Cur;
        if (ring2End >= ring2Limit)
            ring2End = ring2Cur;
        ring2Cur++;
        if (ring2Cur == ring2Limit)
            ring2Cur = ring2Base;
        t->v3();
        t->v1();
    }
}
