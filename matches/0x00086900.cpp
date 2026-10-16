#include "decls/data/game/global.h"

typedef unsigned char u8;
typedef unsigned int u32_86900;
struct Worker_86900 {
    void Reset(int);
};
struct Tail_86900 {
    void Run();
};
struct State_86900 {
    char p0[0x10];
    u32_86900 x10, x14, x18, x1c;
    char p20[0x18];
    u32_86900 x38, x3c;
    char p40[8];
    u8 x48;
};
struct Obj_86900 {
    char p0[8];
    State_86900* state;
    char pc[0x10];
    Worker_86900* worker;
    char p20[0x10];
    Tail_86900* tail;
};
void __fastcall FUN_00086900(Obj_86900* self) {
    self->worker->Reset(0);
    (*(u8*)&DAT_004dd6f0) = 0;
    State_86900* s = self->state;
    s->x48 = 0;
    s->x3c = 0;
    s->x10 = 0;
    s->x14 = 0;
    s->x18 = 0;
    s->x1c = 0;
    s->x38 = 0x10000;
    self->tail->Run();
}