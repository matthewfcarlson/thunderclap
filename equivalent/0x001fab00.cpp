// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fab00 @ 0x001fab00
class MyBufferStream {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool vfunc_4();
    void* buffer;
    int size;
    int position;
    MyBufferStream(void* b, int s) : buffer(b), size(s), position(0) {}
};

struct Converter;
struct Loader;

// The two stack argument words double as a tiny scoped object whose first word
// is overwritten with a vptr after it has been read.
struct ArgSlot {
    void* word0;
    int word1;
    void FUN_00337c00();
    void FUN_00337c10();
};

bool __stdcall FUN_00337c20(MyBufferStream* stream, const char* name, Converter* converter, Loader* loader);

struct Loader {
    char pad00[4];
    Converter* converter;   // 0x04
    bool Load(ArgSlot args);
};

bool Loader::Load(ArgSlot args)
{
    MyBufferStream stream(args.word0, args.word1);
    args.FUN_00337c00();
    if (FUN_00337c20(&stream, "buffer", converter, this)) {
        args.FUN_00337c10();
        return true;
    }
    args.FUN_00337c10();
    return false;
}
