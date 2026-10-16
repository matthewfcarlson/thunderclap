// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_000aef10 @ 0x000aef10
#include "decls/address.h"
void* __cdecl FUN_0008d690(unsigned int size);
extern const char* DAT_0048e0e4;
extern const char* DAT_0048e100;
extern const char* DAT_0048e134;
void FUN_000af480();

class Function {
public:
    Function(const char* name, int count) throw();
    virtual void vf0();
    virtual void vf1();
    static void* operator new(unsigned int size) { return FUN_0008d690(size); }
    int nameRef;
    int owner8;
    int count;
};

template <class T, class R> class Method0 : public Function {
public:
    char flag10;
    char flag11;
    char pad12[6];
    char flag18;
    R (T::*fn)();
    Method0(const char* name, R (T::*f)()) : Function(name, 0) {
        fn = f;
        flag18 = FUN_001d04d0(&DAT_0048e0e4);
    }
};

template <class T, class R, class A, class B> class Method2 : public Function {
public:
    char flag10;
    char flag11;
    char pad12[6];
    char flag18;
    void (T::*fn)(int, bool);
    Method2(const char* name, void (T::*f)(int, bool)) : Function(name, 2) {
        fn = f;
        flag18 = FUN_001d04d0(&DAT_0048e100);
        flag10 = FUN_001d04d0(&DAT_0048e134);
        flag11 = FUN_001d04d0(&DAT_0048e0e4);
    }
};

template <class T, class R, class A> class Method1 : public Function {
public:
    char flag10;
    char flag11;
    char pad12[6];
    char flag18;
    void (T::*fn)(bool);
    Method1(const char* name, void (T::*f)(bool)) : Function(name, 1) {
        fn = f;
        flag18 = FUN_001d04d0(&DAT_0048e100);
        flag10 = FUN_001d04d0(&DAT_0048e0e4);
    }
};

template <class T, class R> class Closure0 : public Method0<T, R> {
public:
    T* target;
    Closure0(const char* name, R (T::*f)(), T* t) throw() : Method0<T, R>(name, f) { target = t; }
};
template <class T, class R, class A, class B> class Closure2 : public Method2<T, R, A, B> {
public:
    T* target;
    Closure2(const char* name, void (T::*f)(int, bool), T* t) throw() : Method2<T, R, A, B>(name, f) { target = t; }
};
template <class T, class R, class A> class Closure1 : public Method1<T, R, A> {
public:
    T* target;
    Closure1(const char* name, void (T::*f)(bool), T* t) throw() : Method1<T, R, A>(name, f) { target = t; }
};

class DeviceManager_aef10 {
public:
    DeviceManager_aef10(int flags) throw();
    char pad[0x170];
    virtual void vf0();
    void FUN_000adc00(int);
};
class Registry_aef10 {
public:
    void FUN_001d3b70(const char* name, Function* fn);
};
Registry_aef10* __cdecl FUN_001d4c90();

class CControllerManager {
public:
    CControllerManager();
    virtual void vf0();
    DeviceManager_aef10* devices;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char b18;
    char flags[9];
    bool FUN_000ae9f0();
    void FUN_000ae9d0(int, bool);
    void FUN_000ae9a0(bool);
};

CControllerManager::CControllerManager() {
    field8 = 1;
    devices = new DeviceManager_aef10(0);
    devices->vf0();
    devices->FUN_000adc00(field8);
    fieldC = 0;
    field10 = 0;
    field14 = 0;
    b18 = 0;
    flags[0] = 0;
    flags[1] = 0;
    FUN_000af480();
    for (int i = 2; i < 9; i++)
        flags[i] = 0;
    Registry_aef10* reg = FUN_001d4c90();
    reg->FUN_001d3b70("ctrl_IsButtonPressed",
        new Closure0<CControllerManager, bool>("ctrl_IsButtonPressed", &CControllerManager::FUN_000ae9f0, this));
    reg->FUN_001d3b70("ctrl_SetButtonLock",
        new Closure2<CControllerManager, void, int, bool>("ctrl_SetButtonLock", &CControllerManager::FUN_000ae9d0, this));
    reg->FUN_001d3b70("ctrl_SetButtonLockAll",
        new Closure1<CControllerManager, void, bool>("ctrl_SetButtonLockAll", &CControllerManager::FUN_000ae9a0, this));
}
