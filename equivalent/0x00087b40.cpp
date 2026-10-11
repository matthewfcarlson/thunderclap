// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00087b40 @ 0x00087b40
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" char __cdecl FUN_001d04d0(const char*);
extern "C" const char DAT_0048e0f0[];
inline void* operator new(unsigned int, void* p) throw() { return p; }

class __declspec(novtable) MethodBase {
  public:
    virtual void m0();
    char pad_04[0xc];
    char retType;
    char pad_11[7];
    char argType;
    char pad_19[3];
    void FUN_001d0480(const char*, int);
    MethodBase(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class A, class R>
class Function1 : public MethodBase {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) : MethodBase(name, 1) {
        fn = f;
        argType = FUN_001d04d0(DAT_0048e0f0);
        retType = FUN_001d04d0(DAT_0048e0f0);
    }
    Fn fn;
};

struct Registry {
    void FUN_001d3b70(const char*, void*);
    void FUN_00087b40(const char* name, const char* (*fn)(const char*));
};

void Registry::FUN_00087b40(const char* name, const char* (*fn)(const char*)) {
    void* mem = FUN_0008d690(0x20);
    Function1<const char*, const char*>* c = 0;
    if (mem)
        c = new (mem) Function1<const char*, const char*>(name, fn);
    FUN_001d3b70(name, c);
}
