// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cec40 @ 0x001cec40
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern char DAT_0048e0e4[];
extern "C" char __cdecl FUN_001d04d0(const char*) throw();

class CScenarioManager { public: bool FUN_dummy(); };

class __declspec(novtable) MethodBase {
  public:
    virtual void m0();
    char pad_04[0x14];
    char retType;
    char pad_19[3];
    MethodBase(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class T, class R>
class Method0 : public MethodBase {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) throw() : MethodBase(name, 0) {
        fn = f;
        retType = FUN_001d04d0(DAT_0048e0e4);
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) throw() : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Frame {
    Closure0<CScenarioManager, bool> closure;
    unsigned int cookie;
    Frame(const char* n, CScenarioManager* o, bool (CScenarioManager::*f)()) throw() : closure(n, o, f) {
        cookie = DAT_004d9968;
    }
};

struct Registry {
    void FUN_001d26d0(const char*, void*);
    void FUN_001cec40(const char* name, CScenarioManager* owner, bool (CScenarioManager::*fn)());
};

void Registry::FUN_001cec40(const char* name, CScenarioManager* owner, bool (CScenarioManager::*fn)()) {
    Frame fr(name, owner, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
