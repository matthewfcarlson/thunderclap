// STATUS: equivalent (tools/equiv.py level 3: 183 inputs, branch coverage 26/26)
// pure3d::SpriteLoader::vfunc_5 @ 0x002bed90
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* __cdecl FUN_00263ea0(unsigned int size);
void* __cdecl FUN_0008d6d0(int size);
unsigned __int64 __cdecl FUN_0027b020(const char* s);
unsigned __int64 __cdecl FUN_002672f0(char* name, int a, int b);

struct Stream {
    void FUN_002647e0(void* dest, unsigned int count, unsigned int size, int flag);
};

struct Reader {
    char pad[0x284];
    Stream* stream;
    int FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class Image {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Chunks {
    Image* FUN_002c0590(Reader* r, int tag);
};

struct NameField {
    unsigned int keyLo;
    unsigned int keyHi;
    void FUN_0027b040(const char* name);
};

class Shader;
namespace pure3d { class Shader; }

struct Sprite {
    Sprite* FUN_002beb20(Image* image, pure3d::Shader* shader, int one, int a, int b, int c);
    Sprite* FUN_002be440(Image** images, int a, int b, int count, pure3d::Shader* shader, int one, int c, int d, int e);
};

namespace content {
namespace LoadInventory {
template <class T>
class DynamicCaster {
public:
    DynamicCaster() {}
    virtual void v0();
    virtual void v1();
};
}
}

class Ctx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual pure3d::Shader* v3(content::LoadInventory::DynamicCaster<pure3d::Shader>* caster, unsigned __int64 hash);
};

class __declspec(novtable) SpriteObjectBase {
public:
    virtual void v0();
    char pad04[4];
    NameField name;
    void FUN_002a4e10(int one);
    SpriteObjectBase(int one) { FUN_002a4e10(one); }
};

namespace pure3d {
class SpriteObject : public SpriteObjectBase {
public:
    SpriteObject() : SpriteObjectBase(1) {}
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void setSprite(Sprite* s);
};
}

namespace pure3d {
class SpriteLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int vfunc_5(pure3d::SpriteObject** out, unsigned __int64* outKey, Reader* r, Ctx* ctx);
    virtual void v6();
    virtual void v7();
    virtual Image* v8(Reader* r, int tag);
    virtual Image* v9(Reader* r, int tag);
    char pad04[0x14 - 4];
    int f14;
    Chunks* f18;
};
}

int pure3d::SpriteLoader::vfunc_5(pure3d::SpriteObject** out, unsigned __int64* outKey, Reader* r, Ctx* ctx)
{
    struct Frame {
        char pad10[3];
        char n;
        int r6;
        Image** arr;
        int r1;
        int r5;
        int r2;
        int r4;
        int r3;
        char nameA[0x100];
        char nameB[0x100];
    } f;
    Image* image = 0;
    f.arr = 0;
    r->stream->FUN_002647e0(&f.n, 1, 1, 1);
    r->stream->FUN_002647e0(f.nameA, (unsigned char)f.n, 1, 1);
    f.nameA[(unsigned char)f.n] = 0;
    r->stream->FUN_002647e0(&f.r1, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r2, 1, 4, 1);
    r->stream->FUN_002647e0(&f.n, 1, 1, 1);
    r->stream->FUN_002647e0(f.nameB, (unsigned char)f.n, 1, 1);
    f.nameB[(unsigned char)f.n] = 0;
    r->stream->FUN_002647e0(&f.r3, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r4, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r5, 1, 4, 1);
    r->stream->FUN_002647e0(&f.r6, 1, 4, 1);
    if (f.r5 > 1 || f.r6 != 0)
        f.arr = (Image**)FUN_0008d6d0(f.r5 * 4);
    int more = r->FUN_002669f0();
    if ((char)more) {
        Image** cursor = f.arr;
        do {
            int id = r->FUN_00266a30();
            if (id == 0x3510) {
                image = f18->FUN_002c0590(r, 0x20);
            } else if (id == 0x19001) {
                if (f.arr != 0) {
                    Image* img = v9(r, 0x20);
                    *cursor = img;
                    img->AddRef();
                    cursor++;
                } else {
                    image = v8(r, 0x20);
                }
            }
            r->FUN_00266be0();
            more = r->FUN_002669f0();
        } while ((char)more);
    }
    Sprite* sprite;
    if (image != 0) {
        unsigned __int64 hash = FUN_0027b020(f.nameB);
        content::LoadInventory::DynamicCaster<pure3d::Shader>* caster = new (&f.r6) content::LoadInventory::DynamicCaster<pure3d::Shader>();
        pure3d::Shader* shader = ctx->v3(caster, hash);
        void* mem = FUN_00263ea0(0xa8);
        if (mem)
            sprite = ((Sprite*)mem)->FUN_002beb20(image, shader, 1, f.r1, f.r2, f14);
        else
            sprite = 0;
    } else if (f.arr != 0) {
        unsigned __int64 hash = FUN_0027b020(f.nameB);
        content::LoadInventory::DynamicCaster<pure3d::Shader>* caster = new (&f.r6) content::LoadInventory::DynamicCaster<pure3d::Shader>();
        pure3d::Shader* shader = ctx->v3(caster, hash);
        void* mem = FUN_00263ea0(0xa8);
        if (mem)
            sprite = ((Sprite*)mem)->FUN_002be440(f.arr, f.r3, f.r4, f.r5, shader, 1, f.r1, f.r2, f14);
        else
            sprite = 0;
    } else {
        return more;
    }
    void* omem = FUN_00263ea0(0x58);
    pure3d::SpriteObject* obj;
    if (omem)
        obj = new (omem) pure3d::SpriteObject();
    else
        obj = 0;
    obj->name.FUN_0027b040(f.nameA);
    obj->setSprite(sprite);
    if (image != 0)
        image->Release();
    *out = obj;
    unsigned __int64 key = FUN_002672f0(f.nameA, 0, 0);
    *outKey = key;
    return (int)key;
}
