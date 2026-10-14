// STATUS: equivalent (tools/equiv.py level 3: 303 inputs, branch coverage 58/58)
// pure3d::MultiControllerLoader::vfunc_5 @ 0x002b2ea0
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Stream {
    char FUN_002647e0(void *dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct NameField_2b2ea0 {
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class LightAnimationController;
class PoseAnimationController;
class CompDrawVisibilityAnimationController;
class SceneGraphTransformAnimationController;
class SceneGraphVisibilityAnimationController;
class TextureAnimationController;
class BillboardQuadGroupAnimationController;
class ParticleController;
class VertexAnimController;
class ProceduralVertexAnimController;
class ShaderAnimationController;
class FrameController;
}

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Inventory_2b2ea0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *v3(void *caster, unsigned __int64 key);
};

namespace pure3d {

class MultiController {
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int mode);
    virtual void v17();
    virtual void v18(int value);
    char pad4[4];
    NameField_2b2ea0 name;
    MultiController *FUN_002b2710(int a, int b, int c);
    void FUN_002b1eb0(void *ctrl);
};

}

void *FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
unsigned __int64 __cdecl FUN_002672f0(const char *s, int a, int b);
void *__cdecl FUN_002b2c00(Inventory_2b2ea0 *inv, const char *name);
void *__cdecl FUN_002b2c30(Inventory_2b2ea0 *inv, const char *name);

class MultiControllerLoader {
public:
    void vfunc_5(pure3d::MultiController **out, unsigned __int64 *outId, Reader *r, Inventory_2b2ea0 *inv);
};

struct Frame_2b2ea0 {
    int c;
    char pad[3];
    unsigned char len;
    union {
        int i;
        float f;
    } v1;
    int type;
    int v4;
    char name2[0x100];
    char name[0x100];
};

#define MAKE_CASE(CLS) \
    { \
        unsigned __int64 key = FUN_0027b020(f.name2); \
        content::LoadInventory::DynamicCaster<pure3d::CLS> *caster = \
            new (&f.c) content::LoadInventory::DynamicCaster<pure3d::CLS>; \
        ctrl = inv->v3(caster, key); \
    }

void MultiControllerLoader::vfunc_5(pure3d::MultiController **out, unsigned __int64 *outId, Reader *r, Inventory_2b2ea0 *inv)
{
    Frame_2b2ea0 f;

    r->stream->FUN_002647e0(&f.v1.i, 1, 4, 1);
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int l1 = f.len;
    r->stream->FUN_002647e0(f.name, l1, 1, 1);
    f.name[l1] = 0;
    r->stream->FUN_002647e0(&f.type, 1, 4, 1);

    int sv;
    if (f.v1.i == 0) {
        r->stream->FUN_002647e0(&f.v1.i, 1, 4, 1);
        sv = (int)f.v1.f;
    } else {
        r->stream->FUN_002647e0(&f.v1.i, 1, 4, 1);
        sv = f.v1.i;
    }
    r->stream->FUN_002647e0(&f.v1.i, 1, 4, 1);
    if (f.v1.i != 0)
        sv = 0;
    r->stream->FUN_002647e0(&f.v4, 1, 4, 1);
    r->stream->FUN_002647e0(&f.v1.i, 1, 4, 1);
    r->stream->FUN_002647e0(&f.c, 1, 4, 1);

    void *mem = FUN_00263ea0(0x58);
    pure3d::MultiController *mc = 0;
    if (mem)
        mc = ((pure3d::MultiController *)mem)->FUN_002b2710(f.c, f.v4, f.v1.i);
    mc->name.FUN_0027b040(f.name);

    switch (f.type) {
    case 0x44464b42:
        mc->v16(5);
        break;
    case 0x445746:
        mc->v16(2);
        break;
    case 0x444c4f48:
        mc->v16(1);
        break;
    case 0x4b424446:
        mc->v16(4);
        break;
    case 0x4b434142:
        mc->v16(3);
        break;
    default:
        mc->v16(0);
        break;
    }
    mc->v18(sv);

    if (r->FUN_002669f0()) {
        do {
            if (r->FUN_00266a30() == 0x121203) {
                r->stream->FUN_002647e0(&f.v4, 1, 4, 1);
                r->stream->FUN_002647e0(&f.len, 1, 1, 1);
                unsigned int l2 = f.len;
                r->stream->FUN_002647e0(f.name2, l2, 1, 1);
                f.name2[l2] = 0;
                r->stream->FUN_002647e0(&f.type, 1, 4, 1);
                void *ctrl;
                switch (f.type) {
                case 0x4d4143:
                    ctrl = FUN_002b2c00(inv, f.name2);
                    break;
                case 0x505845:
                    ctrl = FUN_002b2c30(inv, f.name2);
                    break;
                case 0x475142:
                    MAKE_CASE(BillboardQuadGroupAnimationController)
                    break;
                case 0x584554:
                    MAKE_CASE(TextureAnimationController)
                    break;
                case 0x584645:
                    MAKE_CASE(ParticleController)
                    break;
                case 0x44414853:
                    MAKE_CASE(ShaderAnimationController)
                    break;
                case 0x4554494c:
                    MAKE_CASE(LightAnimationController)
                    break;
                case 0x53495653:
                    MAKE_CASE(SceneGraphVisibilityAnimationController)
                    break;
                case 0x4e525450:
                    MAKE_CASE(PoseAnimationController)
                    break;
                case 0x4e525453:
                    MAKE_CASE(SceneGraphTransformAnimationController)
                    break;
                case 0x53495650:
                    MAKE_CASE(CompDrawVisibilityAnimationController)
                    break;
                case 0x54525650:
                    MAKE_CASE(ProceduralVertexAnimController)
                    break;
                case 0x58545256:
                    MAKE_CASE(VertexAnimController)
                    break;
                default:
                    MAKE_CASE(FrameController)
                    break;
                }
                if (ctrl)
                    mc->FUN_002b1eb0(ctrl);
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    *out = mc;
    *outId = FUN_002672f0(f.name, 0, 0);
}
