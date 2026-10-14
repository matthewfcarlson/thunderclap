// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// RDLReader::vfunc_0 @ 0x0027adf0
struct Stream {
    virtual void s0();
    virtual void release();
    virtual void s2();
    virtual void read(char *buf, int size, int count);
    virtual void s4(); virtual void s5(); virtual void s6();
    virtual void readSize(int *out);
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14();
    virtual int size();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void reset();
    virtual void s22();
    virtual bool valid();
};
extern "C" void __cdecl thunk_FUN_002710d0(Stream **, const char *, int, int, int, int, int, int);
char *__cdecl FUN_0008d690(int size);

class RDLReader {
public:
    virtual void vfunc_0(const char *path);
    virtual int vfunc_1();
    Stream *stream;
    char *data;
    int unused;
    int size;
};

void RDLReader::vfunc_0(const char *path)
{
    vfunc_1();
    thunk_FUN_002710d0(&stream, path, 0, 0, 1, 0, 1, 1);
    stream->reset();
    if (!stream->valid() || stream->size() == 0) {
        stream->release();
        stream = 0;
        return;
    }
    stream->readSize(&size);
    stream->reset();
    data = FUN_0008d690(size);
    stream->read(data, size, 1);
    stream->reset();
    unused = 0;
}
