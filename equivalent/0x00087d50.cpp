// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087d50 @ 0x00087d50
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" char __cdecl FUN_001d04d0(const char*);
extern "C" const char DAT_0048e128[];
inline void* operator new(unsigned int, void* p) throw() { return p; }

class CTimeManager { public: float FUN_dummy(); };

class __declspec(novtable) MethodBase_87d50 {
  public:
    virtual void m0();
    char pad_04[0x14];
    char enabled;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase_87d50(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class T, class R>
class Method0 : public MethodBase_87d50 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_87d50(name, 0) {
        fn = f;
        enabled = FUN_001d04d0(DAT_0048e128);
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_87d50 {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087d50(const char* name, CTimeManager* owner, float (CTimeManager::*fn)());
};

void Registry_87d50::FUN_00087d50(const char* name, CTimeManager* owner, float (CTimeManager::*fn)()) {
    void* mem = FUN_0008d690(0x24);
    Closure0<CTimeManager, float>* c = 0;
    if (mem)
        c = new (mem) Closure0<CTimeManager, float>(name, owner, fn);
    FUN_001d3b70(name, c);
}
