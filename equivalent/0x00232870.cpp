// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 18/18)
// FUN_00232870 @ 0x00232870
#include "compat/ptr.h"
void* __cdecl FUN_00266da0(hulk_intptr n);
int __cdecl FUN_00238190(int n);
void* __cdecl FUN_00263ea0(unsigned int size);

class Stream {
public:
    virtual void v0();
    virtual void v1();
};

class StreamDataReader_232870 : public Stream {
public:
    StreamDataReader_232870* FUN_0023bb00(int a, int b);
};

class StreamStringReader_232870 : public Stream {
public:
    StreamStringReader_232870* FUN_0023b320(int a, int b);
};

class Model_232870 {
public:
    virtual void v0();
    virtual void v1();
};

class BinReader_232870 : public Model_232870 {
public:
    BinReader_232870* FUN_0023c260(Stream* s);
};

class ScriptReader_232870 : public Model_232870 {
public:
    ScriptReader_232870* FUN_0023b470(Stream* s, int flag);
};

class Chunk_232870 {
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
    virtual void v9(int a, Model_232870* m, int b);
    Chunk_232870* FUN_0023b540();
};

Chunk_232870* __stdcall FUN_00232870(const char* data, int a1, unsigned int size, int a3)
{
    void* guard = FUN_00266da0(FUN_00238190(1));
    Stream* stream;
    Model_232870* model;

    if (size > 4 && *(const int*)data == *(const int*)"fig0") {
        void* mem = FUN_00263ea0(0x10);
        stream = 0;
        if (mem)
            stream = ((StreamDataReader_232870*)mem)->FUN_0023bb00(a1, a3);
        stream->v0();
        mem = FUN_00263ea0(0x38);
        model = 0;
        if (mem)
            model = ((BinReader_232870*)mem)->FUN_0023c260(stream);
    } else if (size > 0xc
               && ((const int*)data)[0] == ((const int*)"\r\nfightChunk")[0]
               && ((const int*)data)[1] == ((const int*)"\r\nfightChunk")[1]
               && ((const int*)data)[2] == ((const int*)"\r\nfightChunk")[2]) {
        void* mem = FUN_00263ea0(0x14);
        stream = 0;
        if (mem)
            stream = ((StreamStringReader_232870*)mem)->FUN_0023b320(a1, a3);
        stream->v0();
        mem = FUN_00263ea0(0x3130);
        model = 0;
        if (mem)
            model = ((ScriptReader_232870*)mem)->FUN_0023b470(stream, 1);
    } else {
        FUN_00266da0((hulk_intptr)guard);
        return 0;
    }

    model->v0();
    void* inner = FUN_00266da0(FUN_00238190(2));
    void* mem = FUN_00263ea0(0x30);
    Chunk_232870* dest = 0;
    if (mem)
        dest = ((Chunk_232870*)mem)->FUN_0023b540();
    dest->v9(0, model, -1);
    FUN_00266da0((hulk_intptr)inner);
    model->v1();
    stream->v1();
    FUN_00266da0((hulk_intptr)guard);
    return dest;
}
