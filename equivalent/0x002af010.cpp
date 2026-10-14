// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002af010 @ 0x002af010
class TextureBuilder {
public:
    int f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30;
    TextureBuilder(int a, int b)
    {
        f8 = 0;
        fc = 0;
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f24 = 0;
        f28 = 0;
        f2c = 0;
        f30 = 0;
        f4 = a;
        f20 = 8;
        f1c = b;
    }
    virtual void v0();
};
class Builder {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a, TextureBuilder *tb);
};
Builder *__stdcall FUN_002ae9d0(int a);

void __stdcall FUN_002af010(int a1, int a2, int a3, int a4)
{
    Builder *b = FUN_002ae9d0(a3);
    if (b != 0) {
        TextureBuilder tb(a2, a4);
        b->v9(a1, &tb);
    }
}
