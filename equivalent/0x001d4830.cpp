// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d4830 @ 0x001d4830
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
void *FUN_0008d690(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

class __declspec(novtable) MethodBase_1d4830 {
  public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char argType2;
    char pad_12[6];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char *, int);
    void FUN_001d04b0(const char *name);
    MethodBase_1d4830(const char *n, int k) { FUN_001d0480(n, k); }
};

struct LuaState;
int FUN_001d22a0(LuaState *L);
int FUN_001d4460(LuaState *L);
void FUN_00213550(LuaState *L, MethodBase_1d4830 *obj);
void FUN_002134a0(LuaState *L, int (*fn)(LuaState *), int n);
void FUN_00213790(LuaState *L, int index, const char *name);

struct HandlerTable_1d4830 {
    char data[0x1000];
    void FUN_001d1180(MethodBase_1d4830 *closure);
};
struct WatchList {
    char data[0x4404];
    void FUN_001d27d0();
};

class ScriptHandler {
  public:
    enum script_state { state0 };
    virtual void v0();
    int f04;
    LuaState *L;
    HandlerTable_1d4830 table;
    int f100c;
    char pad1010[0x1060 - 0x1010];
    int f1060;
    char f1064;
    char pad1065[3];
    WatchList watches;
    int f546c;
    int slots[9];

    void FUN_001d3f00(const char *, const char *);
    float FUN_001d2790(const char *);
    const char *FUN_001d27b0(const char *);
    script_state FUN_001d36e0(const char *);
    bool FUN_001d1140(const char *);
    bool FUN_001d1150(const char *);
    void FUN_001d46d0(const char *name, ScriptHandler *obj, int (*fn)(LuaState *));
    void FUN_001d3c90(LuaState **pL);
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
        argType = FUN_001d04d0(TypeTag<A>::get());
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
        argType = FUN_001d04d0(TypeTag<A>::get());
        argType2 = FUN_001d04d0(TypeTag<B>::get());
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
    f04 = 0;
    L = 0;
    f100c = 0;
    f1060 = 0;
    f1064 = 1;
    watches.FUN_001d27d0();
    f546c = 0;
    for (int i = 0; i < 9; i++)
        slots[i] = -1;
    FUN_001d3c90(&L);

    void *mem;
    mem = FUN_0008d690(0x24);
    Closure2<ScriptHandler, void, const char *, const char *> *doString = 0;
    if (mem)
        doString = new (mem) Closure2<ScriptHandler, void, const char *, const char *>("sh_DoString", this, &ScriptHandler::FUN_001d3f00);
    doString->FUN_001d04b0("sh_DoString");
    table.FUN_001d1180(doString);
    LuaState *l_doString = L;
    FUN_00213550(l_doString, doString);
    FUN_002134a0(l_doString, FUN_001d22a0, 1);
    FUN_00213790(l_doString, -10001, "sh_DoString");

    mem = FUN_0008d690(0x24);
    Closure1<ScriptHandler, float, const char *> *getNumber = 0;
    if (mem)
        getNumber = new (mem) Closure1<ScriptHandler, float, const char *>("sh_GetNumber", this, &ScriptHandler::FUN_001d2790);
    getNumber->FUN_001d04b0("sh_GetNumber");
    table.FUN_001d1180(getNumber);
    LuaState *l_getNumber = L;
    FUN_00213550(l_getNumber, getNumber);
    FUN_002134a0(l_getNumber, FUN_001d22a0, 1);
    FUN_00213790(l_getNumber, -10001, "sh_GetNumber");

    mem = FUN_0008d690(0x24);
    Closure1<ScriptHandler, const char *, const char *> *getString = 0;
    if (mem)
        getString = new (mem) Closure1<ScriptHandler, const char *, const char *>("sh_GetString", this, &ScriptHandler::FUN_001d27b0);
    getString->FUN_001d04b0("sh_GetString");
    table.FUN_001d1180(getString);
    LuaState *l_getString = L;
    FUN_00213550(l_getString, getString);
    FUN_002134a0(l_getString, FUN_001d22a0, 1);
    FUN_00213790(l_getString, -10001, "sh_GetString");

    FUN_001d46d0("sh_CallFuncInGlobalState", this, FUN_001d4460);

    mem = FUN_0008d690(0x24);
    Closure1<ScriptHandler, ScriptHandler::script_state, const char *> *processFile = 0;
    if (mem)
        processFile = new (mem) Closure1<ScriptHandler, ScriptHandler::script_state, const char *>("sh_ProcessFile", this, &ScriptHandler::FUN_001d36e0);
    processFile->FUN_001d04b0("sh_ProcessFile");
    table.FUN_001d1180(processFile);
    LuaState *l_processFile = L;
    FUN_00213550(l_processFile, processFile);
    FUN_002134a0(l_processFile, FUN_001d22a0, 1);
    FUN_00213790(l_processFile, -10001, "sh_ProcessFile");

    mem = FUN_0008d690(0x24);
    Closure1<ScriptHandler, bool, const char *> *addWatch = 0;
    if (mem)
        addWatch = new (mem) Closure1<ScriptHandler, bool, const char *>("dbg_AddWatch", this, &ScriptHandler::FUN_001d1140);
    addWatch->FUN_001d04b0("dbg_AddWatch");
    table.FUN_001d1180(addWatch);
    LuaState *l_addWatch = L;
    FUN_00213550(l_addWatch, addWatch);
    FUN_002134a0(l_addWatch, FUN_001d22a0, 1);
    FUN_00213790(l_addWatch, -10001, "dbg_AddWatch");

    mem = FUN_0008d690(0x24);
    Closure1<ScriptHandler, bool, const char *> *delWatch = 0;
    if (mem)
        delWatch = new (mem) Closure1<ScriptHandler, bool, const char *>("dbg_DeleteWatch", this, &ScriptHandler::FUN_001d1150);
    delWatch->FUN_001d04b0("dbg_DeleteWatch");
    table.FUN_001d1180(delWatch);
    LuaState *l_delWatch = L;
    FUN_00213550(l_delWatch, delWatch);
    FUN_002134a0(l_delWatch, FUN_001d22a0, 1);
    FUN_00213790(l_delWatch, -10001, "dbg_DeleteWatch");
}
