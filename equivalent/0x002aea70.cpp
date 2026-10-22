// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 18/24, incomplete)
// pure3d::ImageHandler::vfunc_3 @ 0x002aea70
struct Request;
struct Context;

struct File {
    virtual void AddRef();
    virtual void Release();
    File* FUN_002644d0(Request* req, Context* ctx, int one);
};

struct Request {
    char name[0x100];
    File* file;
    int pad104;
    int allocTag;
};

struct LoadInventory_2aea70;

struct Context {
    char pad0[0x18];
    LoadInventory_2aea70* loader;
    File* file;
    File* FUN_00266880();
    void FUN_00266850(File* f);
    void FUN_00266820(LoadInventory_2aea70* l);
};

struct NameField_2aea70 {
    unsigned int keyLo;
    unsigned int keyHi;
    void FUN_0027b040(const char* name);
};

struct Resource_2aea70 {
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    NameField_2aea70 name;
};

struct SpriteObject {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void setSprite(struct Sprite* s);
    char pad04[4];
    NameField_2aea70 name;
    SpriteObject* FUN_002bdee0();
};

struct Sprite {
    Sprite* FUN_002beb20(Resource_2aea70* image, int zero, int one, int a, int b, int c);
};

struct LoadInventory_2aea70 {
    virtual void v0();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void add(unsigned int keyLo, unsigned int keyHi, void* obj);
    LoadInventory_2aea70* FUN_00266480(int size);
};

namespace pure3d {
class TextureBuilder {
public:
    virtual void vfunc_0();
    Resource_2aea70* tex;
    int flags;
    void* surface;
    int stride;
    void* dest;
    int rows;
    int level;
    int width;
    int height;
    int format;
    int depth;
    int bpp;
    TextureBuilder() : tex(0), flags(0), surface(0), stride(0), dest(0), rows(0), level(0), width(8), height(0), format(0), depth(0), bpp(0) {}
};

class ImageBuilder {
public:
    virtual void vfunc_0();
    Resource_2aea70* image;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    ImageBuilder() : image(0), f08(0), f0c(0), f10(0), f14(0), f18(0) {}
};
}

void* FUN_00263ed0(int size, int tag);
void* FUN_00263ea0(unsigned int size);
void FUN_0028fb20(char* dst, const char* src);

namespace pure3d { class ImageHandler {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Request* req, Context* ctx);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void load(File* file, void* builder);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15();
    char pad04[4];
    int mode;
    char copyName;
    char pad0d[3];
    int f10;
    int f14;
}; }

void pure3d::ImageHandler::vfunc_3(Request* req, Context* ctx)
{
    char name[0x100];

    File* file = ctx->FUN_00266880();
    if (file == 0) {
        void* mem = FUN_00263ed0(0x48, 1);
        if (mem)
            file = ((File*)mem)->FUN_002644d0(req, ctx, 1);
        else
            file = 0;
        ctx->FUN_00266850(file);
    }
    req->file = file;
    file->AddRef();

    if (copyName) {
        const char* src = req->name;
        char* dst = name;
        char c;
        do {
            c = *src;
            *dst = c;
            src++;
            dst++;
        } while (c != 0);
    } else {
        FUN_0028fb20(name, req->name);
    }

    void* lmem = FUN_00263ed0(0x14, req->allocTag);
    LoadInventory_2aea70* loader = 0;
    if (lmem)
        loader = ((LoadInventory_2aea70*)lmem)->FUN_00266480(0x400);

    if (mode == 1) {
        pure3d::TextureBuilder builder;
        load(file, &builder);
        Resource_2aea70* tex = builder.tex;
        if (tex != 0) {
            tex->name.FUN_0027b040(name);
            loader->add(tex->name.keyLo, tex->name.keyHi, tex);
        }
    } else if (mode == 0) {
        pure3d::ImageBuilder builder;
        load(file, &builder);
        Resource_2aea70* image = builder.image;
        if (image != 0) {
            image->name.FUN_0027b040(name);
            loader->add(image->name.keyLo, image->name.keyHi, image);
        }
    } else if (mode == 2) {
        pure3d::ImageBuilder builder;
        load(file, &builder);
        Resource_2aea70* image = builder.image;
        if (image != 0) {
            void* smem = FUN_00263ea0(0xa8);
            Sprite* sprite = 0;
            if (smem)
                sprite = ((Sprite*)smem)->FUN_002beb20(image, 0, 1, f10, f14, vfunc_15());
            void* omem = FUN_00263ea0(0x58);
            SpriteObject* obj = 0;
            if (omem)
                obj = ((SpriteObject*)omem)->FUN_002bdee0();
            obj->setSprite(sprite);
            obj->name.FUN_0027b040(name);
            loader->add(obj->name.keyLo, obj->name.keyHi, obj);
            image->Release();
        }
    }

    file->Release();
    ctx->FUN_00266820(loader);
}
