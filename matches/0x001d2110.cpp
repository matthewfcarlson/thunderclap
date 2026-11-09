#include "decls/data/script.h"
extern "C" void __cdecl FUN_00213550(LuaVMState*, void*);
extern "C" void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
extern "C" void __cdecl FUN_00213790(LuaVMState*, int, const char*);
int __cdecl FUN_001d0cf0(LuaVMState*);
int __cdecl FUN_001d0d30(LuaVMState*);
struct Arg_1d2110 {
    void* x;
    char name[0x80];
    void* value;
    unsigned char flag;
};
class A_1d2110 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void f(Arg_1d2110*);
};
void A_1d2110::f(Arg_1d2110* arg) {
    FUN_00213550(L, arg->x);
    if (arg->flag) {
        FUN_00213550(L, arg->value);
        FUN_002134a0(L, &FUN_001d0d30, 2);
    } else {
        FUN_002134a0(L, &FUN_001d0cf0, 1);
    }
    FUN_00213790(L, 0xffffd8ef, arg->name);
}
