// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001076f0 @ 0x001076f0
#include "compat/ptr.h"
void *__cdecl FUN_0008d690(hulk_uintptr size);

class Weapon_1076f0 {
public:
    virtual void AddRef();
    Weapon_1076f0 *FUN_00109ba0();
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
class CRangedAgent : public AgentBase {
public:
    CRangedAgent(int arg);
    virtual void vfunc_9();
    Weapon_1076f0 *f5c;
    int f60;
    int f64;
    int f68;
    char pad6c[0x80 - 0x6c];
    char b80;
    char b81;
};

CRangedAgent::CRangedAgent(int arg) : AgentBase(arg)
{
    Weapon_1076f0 *w = 0;
    void *mem = FUN_0008d690(0x38);
    if (mem != 0)
        w = ((Weapon_1076f0 *)mem)->FUN_00109ba0();
    f5c = w;
    w->AddRef();
    b80 = 1;
    b81 = 1;
    f68 = 0;
    f64 = 0;
    f60 = 0;
    CRangedAgent::vfunc_9();
}
