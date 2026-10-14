// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0c40 @ 0x000c0c40
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern char DAT_0048e134[];
extern "C" char __cdecl FUN_001d04d0(const char*) throw();

class CFEManager { public: int FUN_dummy(); };

class __declspec(novtable) MethodBase_c0c40 {
  public:
    virtual void m0();
    char pad_04[0x14];
    char retType;
    char pad_19[3];
    MethodBase_c0c40(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase_c0c40 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase_c0c40(name, 0) {
        fn = f;
        retType = FUN_001d04d0(DAT_0048e134);
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame_c0c40 {
    Closure0<CFEManager, int> closure;
    unsigned int cookie;
    Frame_c0c40(const char* n, CFEManager* o, int (CFEManager::*f)()) throw() : closure(n, o, f) {
        cookie = DAT_004d9968;
    }
};

struct Registry_c0c40 {
    void FUN_001d26d0(const char*, void*);
    void FUN_000c0c40(const char* name, CFEManager* owner, int (CFEManager::*fn)());
};

void Registry_c0c40::FUN_000c0c40(const char* name, CFEManager* owner, int (CFEManager::*fn)()) {
    Frame_c0c40 fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
