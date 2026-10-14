// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009b080 @ 0x0009b080
// 0x0009b080: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
extern char DAT_00404cc0[];
extern char DAT_0048e100[];
extern char DAT_0048e134[];
extern char DAT_0048e134[];
extern char DAT_0048e128[];
extern char DAT_0048e134[];
extern char DAT_0048e134[];
extern char DAT_0048e128[];
extern char __cdecl FUN_001d04d0(const void*);

class Callback {
public:
    int vptr;
    char pad04[12];
    char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    char b18;
    char pad19[3];
    void* p1c;
    void FUN_001d0480(void*, int);
    Callback* Init(void* arg, void* value);
};

Callback* Callback::Init(void* arg, void* value)
{
    FUN_001d0480(arg, 6);
    vptr = (int)DAT_00404cc0;
    p1c = value;
    b18 = FUN_001d04d0(DAT_0048e100);
    b10 = FUN_001d04d0(DAT_0048e134);
    b11 = FUN_001d04d0(DAT_0048e134);
    b12 = FUN_001d04d0(DAT_0048e128);
    b13 = FUN_001d04d0(DAT_0048e134);
    b14 = FUN_001d04d0(DAT_0048e134);
    b15 = FUN_001d04d0(DAT_0048e128);
    return this;
}
