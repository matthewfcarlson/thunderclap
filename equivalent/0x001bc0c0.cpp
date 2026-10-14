// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 14/14)
// FUN_001bc0c0 @ 0x001bc0c0
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

typedef unsigned __int64 ID;

namespace pure3d { class DrawableHierarchy; }

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
void __cdecl FUN_00087990();
ID __cdecl FUN_0027b020(const char *s);

struct LoadArgs {
    char path[0x100];       // 0x00
    int a;                  // 0x100
    int b;                  // 0x104
    int kind;               // 0x108
    char flag;              // 0x10c
};

struct Handle_1bc0c0 {
    virtual void v0();
    virtual void Release();
    bool FUN_00266750();
    struct Resource_1bc0c0 *FUN_00266700();
};

struct Drawable {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Draw(int a, int b);
};

struct Resource_1bc0c0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Drawable *Load(void *caster, unsigned int lo, unsigned int hi);
};

struct Loader_1bc0c0 {
    void FUN_00265810(LoadArgs *args, Handle_1bc0c0 **out);
    int FUN_00264870();
    void FUN_00264860(int v);
};

struct Display_1bc0c0 {
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
    virtual float Aspect();
};

struct Renderer_1bc0c0 {
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
    virtual void v12(int a);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void SetMode(int m);
    virtual int GetMode();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void SetFlag(int f);
    virtual bool GetFlag();
};

struct Context {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct View {
    Context *ctx;
    void FUN_00293da0(unsigned int a, unsigned int b, float c);
    void FUN_00293d40(float a, float b, float c);
};

struct Pipe {
    char pad0[0xd8];
    int fd8;                // 0xd8
    void FUN_0028f9a0();
    void FUN_0028faf0(int v);
};

extern Loader_1bc0c0 *DAT_00527c58;
extern Display_1bc0c0 *DAT_0052c2a4;
extern Renderer_1bc0c0 *DAT_0052c2a8;
extern View *DAT_0052c2ac;
extern Pipe *DAT_0052c2b4;

union Slot_1bc0c0 {
    float f;
    unsigned char b;
    unsigned int w;
};

struct Frame_1bc0c0 {
    Slot_1bc0c0 slot;              // 0x00
    Handle_1bc0c0 *handle;         // 0x04
    char caster[4];         // 0x08
    LoadArgs args;          // 0x0c
    char buf1[0x100];       // 0x11c
    char buf2[0x100];       // 0x21c
    unsigned int cookie;    // 0x31c
};

void FUN_001bc0c0(const char *name, int count, const char *dir)
{
    Frame_1bc0c0 f;
    f.cookie = DAT_004d9968;
    if (dir == 0)
        FUN_000964a0(f.buf1, 0x100, "art/%s.p3d", name);
    else
        FUN_000964a0(f.buf1, 0x100, "%s/%s.p3d", dir, name);
    f.handle = 0;
    f.args.path[0] = 0;
    f.args.a = 0;
    f.args.b = 0;
    f.args.flag = 1;
    f.args.kind = 0xb;
    strncpy(f.args.path, f.buf1, 0xff);
    DAT_00527c58->FUN_00265810(&f.args, &f.handle);
    int old = DAT_00527c58->FUN_00264870();
    DAT_00527c58->FUN_00264860(0x3d090);
    while (!f.handle->FUN_00266750())
        FUN_00087990();
    DAT_00527c58->FUN_00264860(old);
    FUN_000964a0(f.buf2, 0x100, "%s.png", name);
    Resource_1bc0c0 *res = f.handle->FUN_00266700();
    ID id = FUN_0027b020(f.buf2);
    content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
    Drawable *dr = res->Load(caster, (unsigned int)id, (unsigned int)(id >> 32));
    f.slot.f = DAT_0052c2a4->Aspect();
    if (dr != 0) {
        if (count > 0) {
            f.slot.f = 1.3333f / f.slot.f;
            unsigned int scale = f.slot.w;
            do {
                DAT_0052c2b4->fd8 = -1;
                DAT_0052c2b4->FUN_0028f9a0();
                DAT_0052c2a8->v12(-1);
                f.slot.b = DAT_0052c2a8->GetFlag();
                DAT_0052c2a8->SetFlag(0);
                int mode = DAT_0052c2a8->GetMode();
                DAT_0052c2a8->SetMode(1);
                DAT_0052c2ac->ctx->v15(0);
                DAT_0052c2ac->ctx->v13(0);
                DAT_0052c2ac->FUN_00293da0(scale, scale, 1.0f);
                DAT_0052c2ac->FUN_00293d40(-0.5f, -0.375f, 1.0f);
                dr->Draw(0, 0);
                DAT_0052c2ac->ctx->v16(0);
                DAT_0052c2a8->SetMode(mode);
                DAT_0052c2a8->SetFlag(f.slot.w);
                DAT_0052c2b4->FUN_0028faf0(1);
            } while (--count != 0);
        }
    }
    if (f.handle != 0)
        f.handle->Release();
    __security_check_cookie(f.cookie);
}
