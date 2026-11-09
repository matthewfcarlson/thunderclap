// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d4830 @ 0x001d4830
// ScriptHandler's constructor (include/decls/data/script.h): the Lua state (0x001d3c90), the watch list, and the
// script functions it binds itself (sh_DoString, sh_GetNumber, sh_GetString, sh_CallFuncInGlobalState,
// sh_ProcessFile, dbg_AddWatch, dbg_DeleteWatch): each a Method<N> / Closure<N> on Function's fields, allocated with
// its own size (0x24 bytes on 32-bit), sorted into the function list and set as a Lua global closure over
// 0x001d22a0.
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
void *FUN_0008d690(unsigned int size);
inline void *operator new(hulk_uintptr, void *p) throw() { return p; }

class __declspec(novtable) MethodBase_1d4830 : public ScriptFunctionFields {
  public:
    virtual void m0();
    void FUN_001d0480(const char *, int);
    void FUN_001d04b0(const char *name);
    MethodBase_1d4830(const char *n, int k) { FUN_001d0480(n, k); }
};

extern "C" int __cdecl FUN_001d22a0(LuaVMState *L);
extern "C" void __cdecl FUN_00213550(LuaVMState *L, void *p);
extern "C" void __cdecl FUN_002134a0(LuaVMState *L, LuaVMCFunction fn, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState *L, int idx, const char *k);

struct HandlerTable_1d4830 : public ScriptFunctionList {
    void FUN_001d1180(ScriptFunctionView *closure);
};
struct WatchList : public ScriptWatchList {
    void FUN_001d27d0();
};

// The fields are a member, not a base: a base after the vfptr would give pointers to ScriptHandler's members (the
// closures' Method<N> slots) the multiple-inheritance form, 8 bytes instead of 4.
class ScriptHandler {
  public:
    enum script_state { state0 };
    virtual void v0();
    ScriptHandlerFields h;

    void FUN_001d3f00(const char *, const char *);
    float FUN_001d2790(const char *);
    const char *FUN_001d27b0(const char *);
    void FUN_001d4460(const char *, const char *, const char *, const char *);
    script_state FUN_001d36e0(const char *);
    bool FUN_001d1140(const char *);
    bool FUN_001d1150(const char *);
    void FUN_001d46d0(const char *name, ScriptHandler *obj,
                      void (ScriptHandler::*fn)(const char *, const char *, const char *, const char *));
    void FUN_001d3c90(LuaVMState **pL);
    ScriptHandler();
};

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return ((char*)&DAT_0048e0f0); } };
template <> struct TypeTag<float> { static const void *get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<ScriptHandler::script_state> { static const void *get() { return &DAT_004c5d10; } };

template <class T, class R, class A>
class Method1 : public MethodBase_1d4830 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1d4830(name, 1) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char *name, T *o, typename Method1<T, R, A>::Fn f) : Method1<T, R, A>(name, f), owner(o) {}
    T *owner;
};

template <class T, class R, class A, class B>
class Method2 : public MethodBase_1d4830 {
  public:
    typedef R (T::*Fn)(A, B);
    Method2(const char *name, Fn f) : MethodBase_1d4830(name, 2) {
        fn = f;
        retType = FUN_001d04d0(TypeTag<R>::get());
        argTypes[0] = FUN_001d04d0(TypeTag<A>::get());
        argTypes[1] = FUN_001d04d0(TypeTag<B>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B>
class Closure2 : public Method2<T, R, A, B> {
  public:
    Closure2(const char *name, T *o, typename Method2<T, R, A, B>::Fn f) : Method2<T, R, A, B>(name, f), owner(o) {}
    T *owner;
};

ScriptHandler::ScriptHandler() {
    h.status = 0;
    h.L = 0;
    h.functions.count = 0;
    h.refreshCount = 0;
    h.ownsState = 1;
    ((WatchList *)&h.watches)->FUN_001d27d0();
    h.coroutineId = 0;
    for (int i = 0; i < 8; i++)
        h.tops[i] = -1;
    h.topIndex = -1;
    FUN_001d3c90(&h.L);

    void *mem;
    mem = FUN_0008d690((int)sizeof(Closure2<ScriptHandler, void, const char *, const char *>));
    Closure2<ScriptHandler, void, const char *, const char *> *doString = 0;
    if (mem)
        doString = new (mem) Closure2<ScriptHandler, void, const char *, const char *>("sh_DoString", this, &ScriptHandler::FUN_001d3f00);
    doString->FUN_001d04b0("sh_DoString");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)doString);
    LuaVMState *l_doString = h.L;
    FUN_00213550(l_doString, doString);
    FUN_002134a0(l_doString, FUN_001d22a0, 1);
    FUN_00213790(l_doString, -10001, "sh_DoString");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, float, const char *>));
    Closure1<ScriptHandler, float, const char *> *getNumber = 0;
    if (mem)
        getNumber = new (mem) Closure1<ScriptHandler, float, const char *>("sh_GetNumber", this, &ScriptHandler::FUN_001d2790);
    getNumber->FUN_001d04b0("sh_GetNumber");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)getNumber);
    LuaVMState *l_getNumber = h.L;
    FUN_00213550(l_getNumber, getNumber);
    FUN_002134a0(l_getNumber, FUN_001d22a0, 1);
    FUN_00213790(l_getNumber, -10001, "sh_GetNumber");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, const char *, const char *>));
    Closure1<ScriptHandler, const char *, const char *> *getString = 0;
    if (mem)
        getString = new (mem) Closure1<ScriptHandler, const char *, const char *>("sh_GetString", this, &ScriptHandler::FUN_001d27b0);
    getString->FUN_001d04b0("sh_GetString");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)getString);
    LuaVMState *l_getString = h.L;
    FUN_00213550(l_getString, getString);
    FUN_002134a0(l_getString, FUN_001d22a0, 1);
    FUN_00213790(l_getString, -10001, "sh_GetString");

    FUN_001d46d0("sh_CallFuncInGlobalState", this, &ScriptHandler::FUN_001d4460);

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, ScriptHandler::script_state, const char *>));
    Closure1<ScriptHandler, ScriptHandler::script_state, const char *> *processFile = 0;
    if (mem)
        processFile = new (mem) Closure1<ScriptHandler, ScriptHandler::script_state, const char *>("sh_ProcessFile", this, &ScriptHandler::FUN_001d36e0);
    processFile->FUN_001d04b0("sh_ProcessFile");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)processFile);
    LuaVMState *l_processFile = h.L;
    FUN_00213550(l_processFile, processFile);
    FUN_002134a0(l_processFile, FUN_001d22a0, 1);
    FUN_00213790(l_processFile, -10001, "sh_ProcessFile");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, bool, const char *>));
    Closure1<ScriptHandler, bool, const char *> *addWatch = 0;
    if (mem)
        addWatch = new (mem) Closure1<ScriptHandler, bool, const char *>("dbg_AddWatch", this, &ScriptHandler::FUN_001d1140);
    addWatch->FUN_001d04b0("dbg_AddWatch");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)addWatch);
    LuaVMState *l_addWatch = h.L;
    FUN_00213550(l_addWatch, addWatch);
    FUN_002134a0(l_addWatch, FUN_001d22a0, 1);
    FUN_00213790(l_addWatch, -10001, "dbg_AddWatch");

    mem = FUN_0008d690((int)sizeof(Closure1<ScriptHandler, bool, const char *>));
    Closure1<ScriptHandler, bool, const char *> *delWatch = 0;
    if (mem)
        delWatch = new (mem) Closure1<ScriptHandler, bool, const char *>("dbg_DeleteWatch", this, &ScriptHandler::FUN_001d1150);
    delWatch->FUN_001d04b0("dbg_DeleteWatch");
    ((HandlerTable_1d4830 *)&h.functions)->FUN_001d1180((ScriptFunctionView *)delWatch);
    LuaVMState *l_delWatch = h.L;
    FUN_00213550(l_delWatch, delWatch);
    FUN_002134a0(l_delWatch, FUN_001d22a0, 1);
    FUN_00213790(l_delWatch, -10001, "dbg_DeleteWatch");
}
