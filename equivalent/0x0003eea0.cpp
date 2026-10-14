// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0003eea0 @ 0x0003eea0
extern "C" char DAT_003f5d3c[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_0048e134[];
extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" char __cdecl FUN_001d04d0(const void*);
class MethodCtor7_3eea0 {
  public:
    int vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* func;
    MethodCtor7_3eea0* Init(void* name, void* fn);
};
MethodCtor7_3eea0* MethodCtor7_3eea0::Init(void* name, void* fn) {
    FUN_001d0480(name, 7);
    vptr = (int)DAT_003f5d3c;
    func = fn;
    result = FUN_001d04d0((void*)((int)DAT_0048e100));
    arg[0] = FUN_001d04d0((void*)((int)DAT_0048e134));
    arg[1] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[2] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[3] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[4] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[5] = FUN_001d04d0((void*)((int)DAT_0048e128));
    arg[6] = FUN_001d04d0((void*)((int)DAT_0048e128));
    return this;
}
