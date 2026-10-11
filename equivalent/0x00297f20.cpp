// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 13/14, incomplete)
// pure3d::scenegraph::ScenegraphLoader::vfunc_5 @ 0x00297f20
extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct RefObject {
    virtual void AddRef();
    virtual void Release();
};

struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy {
public:
    virtual void d0();
    char pad4[4];
    Name name;
    char pad10[0x30];
    void FUN_002a3480();
    DrawableHierarchy() throw() { FUN_002a3480(); }
};

namespace scenegraph {
class Scenegraph : public DrawableHierarchy {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void Finish();
    RefObject *child;
    Scenegraph() throw() { child = 0; }
};
}
}
using pure3d::scenegraph::Scenegraph;

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Frame {
    char pad[3];
    unsigned char len;
    int version;
    char name[0x100];
};

class ScenegraphLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(Scenegraph **outSg, unsigned __int64 *outId, Stream *s, void *ctx);
    RefObject *FUN_00297680(Stream *s, void *ctx);
    RefObject *FUN_00297ba0(Stream *s, void *ctx);
};

void ScenegraphLoader::vfunc_5(Scenegraph **outSg, unsigned __int64 *outId, Stream *s, void *ctx)
{
    Frame f;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    s->reader->FUN_002647e0(&f.version, 1, 4, 1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0x48);
    Scenegraph *sg = 0;
    if (mem)
        sg = new (mem) Scenegraph();
    sg->name.FUN_0027b040(f.name);

    while (s->FUN_002669f0()) {
        int id = s->FUN_00266a30();
        if (id == 0x120101 || id == 0x12010b) {
            RefObject *child;
            if (id == 0x120101) {
                s->FUN_00266a30();
                child = FUN_00297ba0(s, ctx);
            } else {
                s->FUN_00266a30();
                child = FUN_00297680(s, ctx);
            }
            if (child)
                child->AddRef();
            if (sg->child)
                sg->child->Release();
            sg->child = child;
            s->FUN_00266be0();
        }
        s->FUN_00266be0();
    }
    sg->Finish();
    *outSg = sg;
    *outId = FUN_002672f0(f.name, 0);
}
