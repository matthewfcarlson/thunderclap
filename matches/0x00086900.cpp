typedef unsigned char u8;
typedef unsigned int u32;
extern u8 DAT_004dd6f0;
struct Worker {
    void Reset(int);
};
struct Tail {
    void Run();
};
struct State {
    char p0[0x10];
    u32 x10, x14, x18, x1c;
    char p20[0x18];
    u32 x38, x3c;
    char p40[8];
    u8 x48;
};
struct Obj {
    char p0[8];
    State* state;
    char pc[0x10];
    Worker* worker;
    char p20[0x10];
    Tail* tail;
};
void __fastcall FUN_00086900(Obj* self) {
    self->worker->Reset(0);
    DAT_004dd6f0 = 0;
    State* s = self->state;
    s->x48 = 0;
    s->x3c = 0;
    s->x10 = 0;
    s->x14 = 0;
    s->x18 = 0;
    s->x1c = 0;
    s->x38 = 0x10000;
    self->tail->Run();
}