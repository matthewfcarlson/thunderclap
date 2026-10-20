// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 6/6)
// FUN_001c49c0 @ 0x001c49c0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);

class Channel {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetTag(unsigned int tag, int value);
};

class Shader_1c49c0 {
public:
    Shader_1c49c0 *FUN_0028edb0();
    virtual void AddRef();
    virtual void Release();

    char pad4[0xc];
    Channel *channel;   // +0x10
};

class Reader {
public:
    Reader *FUN_001c49c0();

    int f00;
    int f04;
    int f08;
    char f0c;
    Shader_1c49c0 *stream;     // +0x10
    char f14;
    int f18;
    int f1c;
    int f20;
    char f24;
    int f28;
    int f2c;
    int f30;
    char f34;
};

Reader *Reader::FUN_001c49c0() {
    f00 = 0;
    f04 = 0;
    f08 = 0;
    f0c = 0;
    stream = 0;
    f14 = 0;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f34 = 0;

    Shader_1c49c0 *created = 0;
    void *mem = thunk_FUN_0008d690(0x20);
    if (mem != 0) {
        created = ((Shader_1c49c0 *)mem)->FUN_0028edb0();
    }
    if (created != 0) {
        created->AddRef();
    }
    if (stream != 0) {
        stream->Release();
    }
    stream = created;
    created->channel->SetTag(0x444d4c42, 1);
    return this;
}
