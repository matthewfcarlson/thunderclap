// STATUS: equivalent (tools/equiv.py level 3: 2565 inputs, branch coverage 6/6)
// TransitionsLoader::vfunc_5 @ 0x00204f60
struct Reader {
    void FUN_002647e0(void *dst, int a, int size, int count);
};

struct Stream {
    char pad[0x280];
    int index;               // 0x280
    Reader *reader;          // 0x284
    bool FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

union StreamArg {
    Stream *stream;
    unsigned int value;
};

struct Handler {
    void FUN_00204180(unsigned int v);
};

class TransitionsLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual int *vfunc_5(int *out1, int *out2, StreamArg arg, int arg4);
    char pad04[0x10];
    Handler *handler;        // 0x14
    void FUN_00204880(Stream *s, int arg4);
};

int *TransitionsLoader::vfunc_5(int *out1, int *out2, StreamArg arg, int arg4)
{
    Stream *stream = arg.stream;
    stream->reader->FUN_002647e0(&arg.value, 1, 4, 1);
    stream->reader->FUN_002647e0(&arg.value, 1, 4, 1);
    handler->FUN_00204180(arg.value);
    if (stream->FUN_002669f0()) {
        do {
            stream->FUN_00266a30();
            if (stream->FUN_00266c30() == 0x60000720)
                FUN_00204880(stream, arg4);
            stream->FUN_00266be0();
        } while (stream->FUN_002669f0());
    }
    *out1 = 0;
    out2[0] = 0;
    out2[1] = 0;
    return out2;
}
