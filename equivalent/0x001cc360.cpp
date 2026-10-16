// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_001cc360 @ 0x001cc360
#include "decls/address.h"
extern char DAT_0048e100;
extern char DAT_0048e0e4;
extern char DAT_0048e0f0;
void *FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);
inline void *operator new(unsigned int, void *p) throw() { return p; }

template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void *get() { return &DAT_0048e100; } };
template <> struct TypeTag<bool> { static const void *get() { return &DAT_0048e0e4; } };
template <> struct TypeTag<const char *> { static const void *get() { return &DAT_0048e0f0; } };

class __declspec(novtable) MethodBase_1cc360 {
  public:
    virtual void m0();
    char pad_04[0xc];
    char argType;
    char pad_11[7];
    char retType;
    char pad_19[3];
    void FUN_001d0480(const char *, int);
    MethodBase_1cc360(const char *n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R, class A>
class Method1 : public MethodBase_1cc360 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char *name, Fn f) : MethodBase_1cc360(name, 1) {
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

struct Registry_1cc360 {
    void FUN_001d3b70(const char *name, void *closure);
};
Registry_1cc360 *FUN_001d4c90();

struct EventSlot {
    char data[0x28];
    void FUN_00231e50();
};

class CEventManager {
  public:
    CEventManager();
    virtual void vfn0();

    bool FUN_001cbd10(const char *name);
    void FUN_001cb540(bool enabled);
    void FUN_001cb550(const char *name);

    int f04;
    int f08;
    char *buffer;           // 0x0c
    char *cursor;           // 0x10
    char *bufferEnd;        // 0x14
    char pad18[4];
    unsigned char f1c;
    char pad1d[3];
    int f20;
    EventSlot slots[24];    // 0x24
    int w3e4, w3e8, w3ec, w3f0, w3f4, w3f8;
    unsigned char f3fc;
    char pad3fd[3];
    int f400;
};

CEventManager::CEventManager()
{
    f04 = 0;
    f08 = 0;
    buffer = (char *)FUN_0008d6d0(0x7000);
    if (buffer) {
        cursor = buffer;
        bufferEnd = buffer + 0x7000;
    } else {
        cursor = 0;
        bufferEnd = 0;
    }
    f1c = 1;
    f20 = 0;
    for (int i = 0; i < 24; i++)
        slots[i].FUN_00231e50();
    f3fc = 0;
    f400 = 0;

    Registry_1cc360 *reg = FUN_001d4c90();
    if (reg) {
        void *mem;

        mem = FUN_0008d690(0x24);
        Closure1<CEventManager, bool, const char *> *post = 0;
        if (mem)
            post = new (mem) Closure1<CEventManager, bool, const char *>("em_PostEventString", this, &CEventManager::FUN_001cbd10);
        reg->FUN_001d3b70("em_PostEventString", post);

        mem = FUN_0008d690(0x24);
        Closure1<CEventManager, void, bool> *tick = 0;
        if (mem)
            tick = new (mem) Closure1<CEventManager, void, bool>("em_SetTickEnabled", this, &CEventManager::FUN_001cb540);
        reg->FUN_001d3b70("em_SetTickEnabled", tick);

        mem = FUN_0008d690(0x24);
        Closure1<CEventManager, void, const char *> *print = 0;
        if (mem)
            print = new (mem) Closure1<CEventManager, void, const char *>("em_PrintAllEvents", this, &CEventManager::FUN_001cb550);
        reg->FUN_001d3b70("em_PrintAllEvents", print);

        w3e4 = 0x01010101;
        w3e8 = 0x01010101;
        w3ec = 0x01010101;
        w3f0 = 0x01010101;
        w3f4 = 0x01010101;
        w3f8 = 0x01010101;
    }
}
