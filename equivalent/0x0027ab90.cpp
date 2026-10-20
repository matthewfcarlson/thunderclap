// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0027ab90 @ 0x0027ab90
#include "compat/ptr.h"
struct PathRef { const char *s; };

class Stream {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(void *buf, int size, int flag);
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7(int *size);
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual int vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual bool vfn23();
};

extern void *__cdecl FUN_0008d690(hulk_uintptr n);
void thunk_FUN_002710d0(Stream **out, PathRef name, int a, int b, int c, int d, int e, int f);

class RDLReader {
public:
    RDLReader(const char *name);
    virtual void vfn0();

    Stream *stream;
    void *data;
    int pos;
    int size;
    char section[0x40];
};

RDLReader::RDLReader(const char *name)
{
    PathRef ref;
    ref.s = name;
    thunk_FUN_002710d0(&stream, ref, 0, 0, 1, 0, 1, 1);
    stream->vfn21();
    if (stream->vfn23() && stream->vfn15() != 0) {
        stream->vfn7(&size);
        stream->vfn21();
        data = FUN_0008d690(size);
        stream->vfn3(data, size, 1);
        stream->vfn21();
        pos = 0;
    } else {
        stream->vfn1();
        stream = 0;
    }
}
