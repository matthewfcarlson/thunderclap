// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002aef60 @ 0x002aef60
// FUN_002aef60 @ 0x002aef60: builds a texture request for a stream and hands it to the stream owner's handler
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);

class Stream {
public:
    virtual void AddRef();
    virtual void Release();
    Stream *FUN_00264430(unsigned int id, int a, int b);
};

class TextureBuilder {
public:
    virtual void v0();
    int f04;
    int f08, f0c, f10, f14, f18;
    int f1c;
    int f20;
    int f24, f28, f2c, f30;
    TextureBuilder(int a, int b);
};

class Handler_2aef60 {
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
    virtual void Build(Stream *stream, TextureBuilder *builder);
};

class Owner_2aef60 {
public:
    Handler_2aef60 *FUN_002ae980(unsigned int id);
    void FUN_002aef60(unsigned int id, int a, int b);
};

TextureBuilder::TextureBuilder(int a, int b)
{
    f04 = a;
    f08 = 0;
    f0c = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f20 = 8;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f1c = b;
}

void Owner_2aef60::FUN_002aef60(unsigned int id, int a, int b)
{
    void *memory = thunk_FUN_0008d690(0x48);
    Stream *stream = memory ? ((Stream *)memory)->FUN_00264430(id, 0, 0) : 0;
    stream->AddRef();
    Handler_2aef60 *handler = FUN_002ae980(id);
    if (handler) {
        TextureBuilder builder(a, b);
        handler->Build(stream, &builder);
        stream->Release();
    }
}
