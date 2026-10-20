// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000ff180 @ 0x000ff180
// CHand2HandAgent::CHand2HandAgent @ 0x000ff180
#include "compat/ptr.h"
void *__cdecl FUN_0008d690(hulk_uintptr size);

class Weapon_ff180 {
public:
    virtual void AddRef();
    Weapon_ff180 *FUN_00109ba0();
};

class AgentBase {
public:
    AgentBase(int arg);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void vfunc_9();
    char pad4[0x5c - 4];
};

// equiv-map: ??0AgentBase@@QAE@H@Z = 0x000fc760
class CHand2HandAgent : public AgentBase {
public:
    CHand2HandAgent(int arg);
    virtual void vfunc_9();
    Weapon_ff180 *f5c;
    unsigned char b60;
    char pad61[3];
    int f64;
    float f68;
    int f6c;
    float f70;
    char pad74[4];
    unsigned char b78;
    unsigned char b79;
    unsigned char b7a;
    unsigned char b7b;
    unsigned char b7c;
    unsigned char b7d;
    unsigned char b7e;
    unsigned char b7f;
    int f80;
    float f84;
    char pad88[0x174 - 0x88];
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
};

CHand2HandAgent::CHand2HandAgent(int arg) : AgentBase(arg)
{
    Weapon_ff180 *w = 0;
    void *mem = FUN_0008d690(0x38);
    if (mem != 0)
        w = ((Weapon_ff180 *)mem)->FUN_00109ba0();
    f5c = w;
    w->AddRef();
    b60 = 0;
    f64 = 0;
    f6c = 0;
    b7a = 0;
    b7b = 0;
    b7c = 0;
    b78 = 0;
    f80 = 0;
    b79 = 0;
    f70 = -1.0f;
    b7d = 1;
    b7e = 1;
    b7f = 1;
    f68 = 999.0f;
    f84 = 999.0f;
    f17c = 0;
    f178 = 0;
    f174 = 0;
    f18c = 0;
    f188 = 0;
    f184 = 0;
}
