// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009ad40 @ 0x0009ad40
extern "C" char DAT_00404c80[];
extern "C" char DAT_0048e0e4[];
extern "C" char DAT_0048e100[];
extern "C" char DAT_0048e128[];
extern "C" char __cdecl FUN_001d04d0(const void*);

class Callback {
  public:
    int vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback* Init(void*, void*);
};

Callback* Callback::Init(void* arg, void* value) {
    FUN_001d0480(arg, 5);
    vptr = (int)DAT_00404c80;
    p1c = value;
    b18 = FUN_001d04d0((void*)((int)DAT_0048e100));
    b10 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    b11 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    b12 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    b13 = FUN_001d04d0((void*)((int)DAT_0048e0e4));
    b14 = FUN_001d04d0((void*)((int)DAT_0048e128));
    return this;
}
