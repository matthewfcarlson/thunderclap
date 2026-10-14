// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 14/14)
// pure3d::OldMultiControllerLoader::vfunc_5 @ 0x002b3340
// equiv-map: ?FUN_0008d690@@YAPAXI@Z = 0x00263ea0
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class FrameController; }

void *__cdecl FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *name);
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Reader {
    void FUN_002647e0(void *buf, int a, int b, int c);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct ResourceName_2b3340 {
    char data[12];
    void FUN_0027b040(const char *name);
};

struct Controller_2b3340 {
    virtual void v0();
};

struct Factory_2b3340 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Controller_2b3340 *f3(content::LoadInventory::DynamicCaster<pure3d::FrameController> *caster,
                           unsigned int lo, unsigned int hi);
};

struct Loaded_2b3340 {
    char pad0[8];
    ResourceName_2b3340 name;
    Loaded_2b3340 *FUN_002b2710(int a, int b, int c);
    void FUN_002b1eb0(Controller_2b3340 *c);
};

namespace pure3d {

class OldMultiControllerLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual unsigned __int64 vfunc_5(Loaded_2b3340 **out, unsigned __int64 *id, Stream *s, Factory_2b3340 *factory);
};

unsigned __int64 OldMultiControllerLoader::vfunc_5(Loaded_2b3340 **out, unsigned __int64 *id, Stream *s, Factory_2b3340 *factory)
{
    struct Frame {
        char pad0[2];
        unsigned char len;
        unsigned char len2;
        int v10;
        int v14;
        int v18;
        int s1c;
        int s20;
        int s24;
        int s28;
        int s2c;
        int s30;
        char name[0x100];
        char name2[0x100];
        char name3[0x100];
    } f;

    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int len = f.len;
    s->reader->FUN_002647e0(f.name, len, 1, 1);
    f.name[len] = 0;
    s->reader->FUN_002647e0(&f.v10, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v18, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v14, 1, 4, 1);
    s->reader->FUN_002647e0(&f.v10, 1, 4, 1);
    Loaded_2b3340 *loaded = (Loaded_2b3340 *)FUN_0008d690(0x58);
    if (loaded != 0)
        loaded = loaded->FUN_002b2710(f.v10, f.v18, f.v14);
    loaded->name.FUN_0027b040(f.name);
    if (s->FUN_002669f0()) {
        do {
            int chunk = s->FUN_00266a30();
            if (chunk == 0x48a1) {
                s->reader->FUN_002647e0(&f.v18, 1, 4, 1);
                int n = f.v18;
                if (n > 0) {
                    f.v14 = n;
                    do {
                        s->reader->FUN_002647e0(&f.len2, 1, 1, 1);
                        unsigned int l2 = f.len2;
                        s->reader->FUN_002647e0(f.name3, l2, 1, 1);
                        f.name3[l2] = 0;
                        unsigned __int64 h = FUN_0027b020(f.name3);
                        new ((void *)&f.v10) content::LoadInventory::DynamicCaster<pure3d::FrameController>;
                        Controller_2b3340 *c = factory->f3(
                            (content::LoadInventory::DynamicCaster<pure3d::FrameController> *)&f.v10,
                            (unsigned int)h, (unsigned int)(h >> 32));
                        loaded->FUN_002b1eb0(c);
                        s->reader->FUN_002647e0(&f.s2c, 1, 4, 1);
                        s->reader->FUN_002647e0(&f.s20, 1, 4, 1);
                        s->reader->FUN_002647e0(&f.s24, 1, 4, 1);
                        f.v14--;
                    } while (f.v14 != 0);
                }
            } else if (chunk == 0x48a2) {
                s->reader->FUN_002647e0(&f.len, 1, 1, 1);
                unsigned int l2 = f.len;
                s->reader->FUN_002647e0(f.name2, l2, 1, 1);
                f.name2[l2] = 0;
                unsigned __int64 h = FUN_0027b020(f.name2);
                new ((void *)&f.v10) content::LoadInventory::DynamicCaster<pure3d::FrameController>;
                Controller_2b3340 *c = factory->f3(
                    (content::LoadInventory::DynamicCaster<pure3d::FrameController> *)&f.v10,
                    (unsigned int)h, (unsigned int)(h >> 32));
                loaded->FUN_002b1eb0(c);
                s->reader->FUN_002647e0(&f.s30, 1, 4, 1);
                s->reader->FUN_002647e0(&f.s1c, 1, 4, 1);
                s->reader->FUN_002647e0(&f.s28, 1, 4, 1);
            }
            s->FUN_00266be0();
        } while (s->FUN_002669f0());
    }
    *out = loaded;
    return *id = FUN_002672f0(f.name, 0, 0);
}

}
