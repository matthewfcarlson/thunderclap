// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087a90 @ 0x00087a90
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" char __cdecl FUN_001d04d0(const char*);
extern "C" const char DAT_0048e128[];
inline void* operator new(unsigned int, void* p) throw() { return p; }

class __declspec(novtable) MethodBase {
  public:
    virtual void m0();
    char pad_04[0x14];
    char enabled;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R>
class Function0 : public MethodBase {
  public:
    typedef R (*Fn)();
    Function0(const char* name, Fn f) : MethodBase(name, 0) {
        fn = f;
        enabled = FUN_001d04d0(DAT_0048e128);
    }
    Fn fn;
};

struct Registry {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087a90(const char* name, float (*fn)());
};

void Registry::FUN_00087a90(const char* name, float (*fn)()) {
    void* mem = FUN_0008d690(0x20);
    Function0<float>* c = 0;
    if (mem)
        c = new (mem) Function0<float>(name, fn);
    FUN_001d3b70(name, c);
}
