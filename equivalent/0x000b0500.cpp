// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_000b0500 @ 0x000b0500
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
class CHapticControllerManager;


template <class T> struct TypeTag;
template <> struct TypeTag<void> { static const void* get() { return ((char*)&DAT_0048e100); } };
template <> struct TypeTag<int> { static const void* get() { return ((char*)&DAT_0048e134); } };
template <> struct TypeTag<float> { static const void* get() { return ((char*)&DAT_0048e128); } };
template <> struct TypeTag<bool> { static const void* get() { return &DAT_0048e0e4; } };

struct HeapObj {
    static void* operator new(unsigned size) throw();
};

class MethodBase_b0500 : public HeapObj {
  public:
    MethodBase_b0500(const char* name, int argCount) throw();
    virtual void m0();
    char pad_04[0x10 - 4];
    char argType[4];
    char pad_14[4];
    char retType;
    char pad_19[3];
};

template <class T, class R>
class Method0 : public MethodBase_b0500 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_b0500(name, 0), fn(f) {
        retType = FUN_001d04d0(TypeTag<R>::get());
    }
    Fn fn;
};

template <class T, class R, class A>
class Method1 : public MethodBase_b0500 {
  public:
    typedef R (T::*Fn)(A);
    Method1(const char* name, Fn f) throw() : MethodBase_b0500(name, 1), fn(f) {
        retType = FUN_001d04d0(TypeTag<R>::get());
        argType[0] = FUN_001d04d0(TypeTag<A>::get());
    }
    Fn fn;
};

template <class T, class R, class A, class B, class C, class D>
class Method4 : public MethodBase_b0500 {
  public:
    typedef R (T::*Fn)(A, B, C, D);
    Method4(const char* name, Fn f) throw() : MethodBase_b0500(name, 4), fn(f) {
        retType = FUN_001d04d0(TypeTag<R>::get());
        argType[0] = FUN_001d04d0(TypeTag<A>::get());
        argType[1] = FUN_001d04d0(TypeTag<B>::get());
        argType[2] = FUN_001d04d0(TypeTag<C>::get());
        argType[3] = FUN_001d04d0(TypeTag<D>::get());
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

template <class T, class R, class A>
class Closure1 : public Method1<T, R, A> {
  public:
    Closure1(const char* name, T* o, typename Method1<T, R, A>::Fn f) throw() : Method1<T, R, A>(name, f), owner(o) {}
    T* owner;
};

template <class T, class R, class A, class B, class C, class D>
class Closure4 : public Method4<T, R, A, B, C, D> {
  public:
    Closure4(const char* name, T* o, typename Method4<T, R, A, B, C, D>::Fn f) throw()
        : Method4<T, R, A, B, C, D>(name, f), owner(o) {}
    T* owner;
};

struct Registry_b0500 {
    void FUN_001d3b70(const char* name, void* closure);
};
Registry_b0500* FUN_001d4c90();
void* FUN_0008d690(unsigned size);

class Source_b0500 {
  public:
    void* FUN_000ae640(int index);
};

class IDevice_b0500 {
  public:
    virtual void init();
    virtual void release();
};

class CHapticController_b0500 : public IDevice_b0500 {
  public:
    CHapticController_b0500* FUN_000afbf0(void* source);
    void FUN_000afb80(int flag);
};

class CHapticControllerManager {
  public:
    CHapticControllerManager(Source_b0500* source);
    virtual void v0();
    char field_04;
    unsigned char field_05;
    char pad_06[2];
    IDevice_b0500* device;

    void FUN_000afea0(int, float, float, float);
    void FUN_000afe80();
    void FUN_000afe10(bool);
};

CHapticControllerManager::CHapticControllerManager(Source_b0500* source) {
    field_04 = 0;
    field_05 = 1;
    device = 0;

    CHapticController_b0500* dev = (CHapticController_b0500*)FUN_0008d690(0x1c);
    if (dev != 0)
        dev = dev->FUN_000afbf0(source->FUN_000ae640(0));
    if (dev != 0)
        dev->init();
    if (device != 0)
        device->release();
    device = dev;
    dev->FUN_000afb80(field_05);

    Registry_b0500* reg = FUN_001d4c90();

    Closure4<CHapticControllerManager, void, int, float, float, float>* playRumble =
        new Closure4<CHapticControllerManager, void, int, float, float, float>("hcm_PlayRumble", this, &CHapticControllerManager::FUN_000afea0);
    reg->FUN_001d3b70("hcm_PlayRumble", playRumble);

    Closure0<CHapticControllerManager, void>* resetRumble =
        new Closure0<CHapticControllerManager, void>("hcm_ResetRumble", this, &CHapticControllerManager::FUN_000afe80);
    reg->FUN_001d3b70("hcm_ResetRumble", resetRumble);

    Closure1<CHapticControllerManager, void, bool>* enableRumble =
        new Closure1<CHapticControllerManager, void, bool>("hcm_EnableRumble", this, &CHapticControllerManager::FUN_000afe10);
    reg->FUN_001d3b70("hcm_EnableRumble", enableRumble);
}
