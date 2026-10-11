// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 18/18)
// FUN_00232870 @ 0x00232870
void* __cdecl FUN_00266da0(int n);
int __cdecl FUN_00238190(int n);
void* __cdecl FUN_00263ea0(unsigned int size);

class Stream {
public:
    virtual void v0();
    virtual void v1();
};

class StreamFig : public Stream {
public:
    StreamFig* FUN_0023bb00(int a, int b);
};

class StreamChunk : public Stream {
public:
    StreamChunk* FUN_0023b320(int a, int b);
};

class Model {
public:
    virtual void v0();
    virtual void v1();
};

class ModelFig : public Model {
public:
    ModelFig* FUN_0023c260(Stream* s);
};

class ModelChunk : public Model {
public:
    ModelChunk* FUN_0023b470(Stream* s, int flag);
};

class Dest {
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
    virtual void v9(int a, Model* m, int b);
    Dest* FUN_0023b540();
};

Dest* __stdcall FUN_00232870(const char* data, int a1, unsigned int size, int a3)
{
    void* guard = FUN_00266da0(FUN_00238190(1));
    Stream* stream;
    Model* model;

    if (size > 4 && *(const int*)data == *(const int*)"fig0") {
        void* mem = FUN_00263ea0(0x10);
        stream = 0;
        if (mem)
            stream = ((StreamFig*)mem)->FUN_0023bb00(a1, a3);
        stream->v0();
        mem = FUN_00263ea0(0x38);
        model = 0;
        if (mem)
            model = ((ModelFig*)mem)->FUN_0023c260(stream);
    } else if (size > 0xc
               && ((const int*)data)[0] == ((const int*)"\r\nfightChunk")[0]
               && ((const int*)data)[1] == ((const int*)"\r\nfightChunk")[1]
               && ((const int*)data)[2] == ((const int*)"\r\nfightChunk")[2]) {
        void* mem = FUN_00263ea0(0x14);
        stream = 0;
        if (mem)
            stream = ((StreamChunk*)mem)->FUN_0023b320(a1, a3);
        stream->v0();
        mem = FUN_00263ea0(0x3130);
        model = 0;
        if (mem)
            model = ((ModelChunk*)mem)->FUN_0023b470(stream, 1);
    } else {
        FUN_00266da0((int)guard);
        return 0;
    }

    model->v0();
    void* inner = FUN_00266da0(FUN_00238190(2));
    void* mem = FUN_00263ea0(0x30);
    Dest* dest = 0;
    if (mem)
        dest = ((Dest*)mem)->FUN_0023b540();
    dest->v9(0, model, -1);
    FUN_00266da0((int)inner);
    model->v1();
    stream->v1();
    FUN_00266da0((int)guard);
    return dest;
}
