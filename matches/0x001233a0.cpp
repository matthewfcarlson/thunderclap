#include "gen/hulkfight.h"

extern "C" void _ReadWriteBarrier();
class Base {
  public:
    Base();
};
class Sub {
  public:
    Sub();
};
class Obj_1233a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern char VT_1233a0[];

hulkfight::ai::PathFormationAction* hulkfight::ai::PathFormationAction::FUN_001233a0(int a, void* __p1) { Obj_1233a0 * b = (Obj_1233a0 *)__p1;

    char* p = (char*)this;
    ((Base*)this)->Base::Base();
    *(void**)p = VT_1233a0;
    *(int*)(p + 0x50) = 0;
    *(int*)(p + 0x54) = 0;
    *(int*)(p + 0x58) = 0;
    *(int*)(p + 0x60) = 0;
    *(int*)(p + 0x7c) = 0;
    *(int*)(p + 0x80) = 0;
    *(int*)(p + 0x84) = 0;
    *(int*)(p + 0x8c) = 0;
    *(int*)(p + 0x90) = 0;
    *(int*)(p + 0x94) = 0;
    _ReadWriteBarrier();
    *(int*)(p + 0x9c) = 0;
    ((Sub*)(p + 0xc0))->Sub::Sub();
    *(char*)(p + 0xc8) = 0;
    *(int*)(p + 0xcc) = 0;
    *(int*)(p + 0x7c) = a;
    if (b)
        b->AddRef();
    Obj_1233a0* old = *(Obj_1233a0**)(p + 0x80);
    if (old)
        old->Release();
    *(Obj_1233a0**)(p + 0x80) = b;
    return (PathFormationAction*)(this);
}
