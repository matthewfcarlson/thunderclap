// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e0620 @ 0x002e0620
// equiv-map: ??0Base@@QAE@XZ = 0x002a5060
class Base {
public:
    Base();
    virtual void f0();
    char pad4[0x40 - 4];
};

class Skin_2e0620 {
public:
    Skin_2e0620 *FUN_002c86d0(int a, int b, int c);
    virtual void f0();
};

void *__cdecl FUN_0008d690(unsigned int n);

namespace pure3d {
class PrimGroupSkinnedPC : public Base {
public:
    PrimGroupSkinnedPC(int a, int b, int c);
    virtual void f0();
    int f40, f44, f48, f4c, f50;
    char pad54[4];
    int f58;
    char pad5c[4];
    int f60, f64;
    Skin_2e0620 *f68;
};
}

pure3d::PrimGroupSkinnedPC::PrimGroupSkinnedPC(int a, int b, int c)
{
    f40 = 0;
    f44 = 0;
    f48 = a;
    f4c = b;
    f50 = -1;
    f58 = 0;
    f60 = 0;
    f64 = 0;
    Skin_2e0620 *s = 0;
    void *mem = FUN_0008d690(0x5c);
    if (mem != 0)
        s = ((Skin_2e0620 *)mem)->FUN_002c86d0(a, b, 0);
    f68 = s;
    s->f0();
}
