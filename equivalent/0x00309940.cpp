// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00309940 @ 0x00309940
union Word {
    int i;
    float f;
};

struct Src {
    char pad0[4];
    int f4, f8, fc, f10, f14, f18;
};

class Obj {
public:
    char pad0[0x4c];
    Word f4c, f50, f54, f58, f5c, f60;
    char pad64[4];
    int f68, f6c, f70, f74, f78, f7c;
    char pad80[0xf0 - 0x80];
    float ff0;

    void FUN_00309940(Src *s);
};

void Obj::FUN_00309940(Src *s)
{
    f68 = s->f4;
    f6c = s->f8;
    f70 = s->fc;
    f74 = s->f10;
    f78 = s->f14;
    f7c = s->f18;
    f4c.i = f68;
    f50.i = f6c;
    f54.i = f70;
    f58.i = f74;
    f5c.i = f78;
    f60.i = f7c;
    ff0 = (((volatile Word *)&f60)->f + ((volatile Word *)&f58)->f + ((volatile Word *)&f4c)->f) * 0.33f;
}
