// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009ae50 @ 0x0009ae50
// Method7 registration constructor: base init, vftable, then the seven result/argument type tags.
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e0e4[];
extern "C" char DAT_0048e128[];
extern "C" char DAT_00404c90[];
extern "C" char __cdecl FUN_001d04d0(const void*);

class Callback {
  public:
    int vptr;
    char pad4[12];
    char arg[7];
    char pad17;
    char result;
    char pad19[3];
    void* owner;
    void FUN_001d0480(void*, int);
    Callback* Init(void*, void*);
};

Callback* Callback::Init(void* name, void* value) {
    FUN_001d0480(name, 7);
    vptr = (int)DAT_00404c90;
    owner = value;
    result = FUN_001d04d0((void*)((int)DAT_0048e100));
    arg[0] = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    arg[1] = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    arg[2] = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    arg[3] = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    arg[4] = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    arg[5] = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    arg[6] = FUN_001d04d0((void*)((int)DAT_0048e128));
    return this;
}
