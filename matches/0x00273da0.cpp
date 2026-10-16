#include "gen/core.h"

struct Sink_273da0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Do(int a, char* b);
};
struct Sub_273da0 {
    virtual void Fin();
    virtual void Rel();
};
struct Ev_273da0 {
    char pad[0x12c];
};
struct Inner_273da0 {
    char pad0[4];
    Sub_273da0 sub;
    char pad1[4];
    Sink_273da0* sink;
    char pad2[4];
    int f14;
    char pad3[4];
    char f1c;
    char pad4;
    char name[0x10e];
    char ev[0x30];
    int h;
};
struct Ev2 {
    bool Test();
    void Run();
};

int core::FileCloseRequest::vfunc_1() {
    Sink_273da0* s = (*(Inner_273da0 * *)&this->f_08)->sink;
    if (!((Ev2*)((char*)(*(Inner_273da0 * *)&this->f_08) + 0x12c))->Test())
        s->Do(*(int*)((char*)(*(Inner_273da0 * *)&this->f_08) + 0x15c), (char*)(*(Inner_273da0 * *)&this->f_08) + 0x1e);
    else
        ((Ev2*)((char*)(*(Inner_273da0 * *)&this->f_08) + 0x12c))->Run();
    (*(Inner_273da0 * *)&this->f_08)->f1c = 0;
    (*(Inner_273da0 * *)&this->f_08)->sub.Fin();
    (*(Inner_273da0 * *)&this->f_08)->f14 = 0;
    (*(Inner_273da0 * *)&this->f_08)->sub.Rel();
    return 1;
}
