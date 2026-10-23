// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 4/4)
// FUN_00240a10 @ 0x00240a10
#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"

class Singleton_240a10 {
public:
    virtual void v0();
    virtual void v1();
};

struct Handle_240a10 {
    char pad0[0x68];
    int id;                  // 0x68
};

struct Pool_240a10 {
    void FUN_002659a0(int id);
};

struct Resource_240a10 {
    void FUN_00240060();
};


void __cdecl FUN_00242c10(char *guard);
Handle_240a10 *__cdecl FUN_00245330();
Handle_240a10 *__cdecl FUN_00256660();
Handle_240a10 *__cdecl FUN_00241660();
Handle_240a10 *__cdecl FUN_0024d5a0();
void __cdecl FUN_0024d630();
void __cdecl FUN_0008d330(void *p);

Singleton_240a10 *__cdecl FUN_00255d20();
Singleton_240a10 *__cdecl FUN_00255480();
Singleton_240a10 *__cdecl FUN_00254e70();
Singleton_240a10 *__cdecl FUN_00254a70();
Singleton_240a10 *__cdecl FUN_00254640();
Singleton_240a10 *__cdecl FUN_00253c50();
Singleton_240a10 *__cdecl FUN_00253770();
Singleton_240a10 *__cdecl FUN_00253390();
Singleton_240a10 *__cdecl FUN_00252fb0();
Singleton_240a10 *__cdecl FUN_00252b50();
Singleton_240a10 *__cdecl FUN_002527a0();
Singleton_240a10 *__cdecl FUN_00252370();
Singleton_240a10 *__cdecl FUN_002518d0();
Singleton_240a10 *__cdecl FUN_002513c0();
Singleton_240a10 *__cdecl FUN_00250db0();
Singleton_240a10 *__cdecl FUN_002509b0();
Singleton_240a10 *__cdecl FUN_00250540();
Singleton_240a10 *__cdecl FUN_002500d0();
Singleton_240a10 *__cdecl FUN_0024fc50();
Singleton_240a10 *__cdecl FUN_0024f810();
Singleton_240a10 *__cdecl FUN_0024ea00();
Singleton_240a10 *__cdecl FUN_0024e540();

void FUN_00240a10()
{
    FUN_00242c10(((char*)&DAT_004e5cac));
    if ((*(unsigned char*)&DAT_004e5ca4) & 1) {
        { int poolId = FUN_00245330()->id; (*(Pool_240a10**)&DAT_00527c58)->FUN_002659a0(poolId); } // MSVC evaluates the argument first
        { int poolId = FUN_00256660()->id; (*(Pool_240a10**)&DAT_00527c58)->FUN_002659a0(poolId); } // MSVC evaluates the argument first
        { int poolId = FUN_00241660()->id; (*(Pool_240a10**)&DAT_00527c58)->FUN_002659a0(poolId); } // MSVC evaluates the argument first
        { int poolId = FUN_0024d5a0()->id; (*(Pool_240a10**)&DAT_00527c58)->FUN_002659a0(poolId); } // MSVC evaluates the argument first
    }
    FUN_0024d630();
    FUN_00255d20()->v1();
    FUN_00255480()->v1();
    FUN_00254e70()->v1();
    FUN_00254a70()->v1();
    FUN_00254640()->v1();
    FUN_00253c50()->v1();
    FUN_00253770()->v1();
    FUN_00253390()->v1();
    FUN_00252fb0()->v1();
    FUN_00252b50()->v1();
    FUN_002527a0()->v1();
    FUN_00252370()->v1();
    FUN_002518d0()->v1();
    FUN_002513c0()->v1();
    FUN_00250db0()->v1();
    FUN_002509b0()->v1();
    FUN_00250540()->v1();
    FUN_002500d0()->v1();
    FUN_0024fc50()->v1();
    FUN_0024f810()->v1();
    FUN_0024ea00()->v1();
    FUN_0024e540()->v1();
    Resource_240a10 *res = (*(Resource_240a10**)&DAT_004e5ca0);
    if (res) {
        res->FUN_00240060();
        FUN_0008d330(res);
    }
    (*(Resource_240a10**)&DAT_004e5ca0) = 0;
}
