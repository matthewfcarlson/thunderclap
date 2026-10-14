// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002aeec0 @ 0x002aeec0
class TextureBuilder {
public:
    int result, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30;
    TextureBuilder(int a, int b, int c, int d, int e)
    {
        result = 0;
        f8 = 0;
        fc = 0;
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1c = 0;
        f20 = a;
        f24 = b;
        f28 = c;
        f2c = d;
        f30 = e;
    }
    virtual void v0();
};

class ImageHandler {
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
    virtual void v9(int stream, TextureBuilder *tb);
};

class ImageRegistry {
public:
    char pad0[0x8c];
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;

    ImageHandler *FUN_002ae9d0(int type);
    int FUN_002aeec0(int stream, int unused, int type);
};

int ImageRegistry::FUN_002aeec0(int stream, int unused, int type)
{
    ImageHandler *h = FUN_002ae9d0(type);
    if (h == 0)
        return 0;
    TextureBuilder tb(p94, p98, p9c, pa0, p8c);
    h->v9(stream, &tb);
    return tb.result;
}
