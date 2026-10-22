// FUN_00232ae0 @ 0x00232ae0
// FUN_00232ae0 @ 0x00232ae0: reads a source into a temporary buffer and hands it to FUN_00232870 through a stream
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "gen/content.h"
int __cdecl FUN_00238190(int n);
int __cdecl FUN_00266da0(int mode);
void *__cdecl FUN_0008d6d0(unsigned int size);
void *thunk_FUN_0008d690(unsigned int size);
void __cdecl thunk_FUN_00267090(void *p);

struct LoadStream_232ae0 {
    content::LoadStream *FUN_00264190(void *data, unsigned int size);
};

class Source_232ae0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void Read(void *buffer, unsigned int size, int flag);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void Rewind();
    virtual void s22();
    virtual void s23();
    virtual int GetOption();
};

class Loader_232ae0 {
public:
    int FUN_00232870(void *data, content::LoadStream *stream, unsigned int size, int option);
    int FUN_00232ae0(Source_232ae0 *source, unsigned int size);
};

int Loader_232ae0::FUN_00232ae0(Source_232ae0 *source, unsigned int size)
{
    int saved = FUN_00266da0(FUN_00238190(2));
    void *buffer = FUN_0008d6d0(size);
    source->Read(buffer, size, 1);
    source->Rewind();
    void *memory = thunk_FUN_0008d690(0x48);
    content::LoadStream *stream = memory ? ((LoadStream_232ae0*)(((content::LoadStream *)memory)))->FUN_00264190(buffer, size) : 0;
    stream->vfunc_0();
    int result = FUN_00232870(buffer, stream, size, source->GetOption());
    stream->vfunc_1();
    thunk_FUN_00267090(buffer);
    FUN_00266da0(saved);
    return result;
}
