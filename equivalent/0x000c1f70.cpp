// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 18/18)
// FUN_000c1f70 @ 0x000c1f70
#include "decls/address.h"
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

namespace pure3d { class Texture; class Shader; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Pair_c1f70 {
    int a;
    int b;
};

class CUnlockable {
public:
    virtual void v0();
};

class CUnlockableBlonskyFile : public CUnlockable {
public:
    Pair_c1f70* FUN_00091d00();
    const char* FUN_00091d50();
};

struct ItemTable_c1f70 {
    CUnlockable* FUN_00092ad0(int index);
    Pair_c1f70* FUN_00092bb0(int index);
};

struct Manager_c1f70 {
    int FUN_000f7240(int a, int b);
};
Manager_c1f70* __cdecl FUN_000fc1b0();

struct NameSource_c1f70 {
    const char* FUN_0027b010();
};

struct TextEntry_c1f70 {
    void FUN_000f7a10(int id, int flag);
    void FUN_000f8500(const char* name, Manager_c1f70* manager, int flag);
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14];
    TextEntry_c1f70 entry;
};

class TextLabel : public FEObject {
public:
    virtual void vfunc_4();
};

class TextWindow : public FEObject {
public:
    virtual void vfunc_4();
};

FEObject* __cdecl FUN_000fc260(const char* name);

struct Resource_c1f70 {
    char pad[0x10];
    int f10;
};

struct Slot_c1f70 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void set(int what, int value);
    char pad[0xc];
    Slot_c1f70* inner;
};

struct ShaderHolder {
    char pad[0x10];
    Slot_c1f70* slot;
};

struct Loader_c1f70 {
    virtual void init();
    virtual void release();
    virtual void a2();
    virtual Resource_c1f70* find(content::LoadInventory::DynamicCaster<pure3d::Texture>* caster, unsigned __int64 key);
    Loader_c1f70* FUN_00266480(int size);
};

struct Inventory_c1f70 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual ShaderHolder* find(content::LoadInventory::DynamicCaster<pure3d::Shader>* caster, unsigned __int64 key);
};

extern Inventory_c1f70* DAT_004dd9cc;

void* __cdecl FUN_00263ea0(int size);
int __cdecl FUN_000964a0(char* dst, int size, const char* fmt, ...);

struct Frame_c1f70 {
    char path[0x100];
    char image[0x100];
};

class BlonskyScreen {
public:
    char pad0[0x4c];
    ItemTable_c1f70* items;
    void FUN_000bc3c0(const char* path, Loader_c1f70* loader, int kind);
    void FUN_000c1f70(int index);
};

void BlonskyScreen::FUN_000c1f70(int index)
{
    unsigned int cookie = DAT_004d9968;
    Frame_c1f70 frame;

    if (items != 0) {
        CUnlockableBlonskyFile* file = dynamic_cast<CUnlockableBlonskyFile*>(items->FUN_00092ad0(index));
        if (file != 0) {
            TextLabel* title = dynamic_cast<TextLabel*>(FUN_000fc260("blonsky_file_title"));
            if (title != 0) {
                Pair_c1f70* p = items->FUN_00092bb0(index);
                int id = FUN_000fc1b0()->FUN_000f7240(p->a, p->b);
                if (id == -1) {
                    Manager_c1f70* m = FUN_000fc1b0();
                    NameSource_c1f70* ns = (NameSource_c1f70*)items->FUN_00092bb0(index);
                    title->entry.FUN_000f8500(ns->FUN_0027b010(), m, 1);
                } else {
                    title->entry.FUN_000f7a10(id, 0);
                }
            }
            TextWindow* text = dynamic_cast<TextWindow*>(FUN_000fc260("blonsky_file_text"));
            if (text != 0) {
                Pair_c1f70* q = file->FUN_00091d00();
                int id = FUN_000fc1b0()->FUN_000f7240(q->a, q->b);
                if (id == -1) {
                    Manager_c1f70* m = FUN_000fc1b0();
                    NameSource_c1f70* ns = (NameSource_c1f70*)file->FUN_00091d00();
                    text->entry.FUN_000f8500(ns->FUN_0027b010(), m, 1);
                } else {
                    text->entry.FUN_000f7a10(id, 0);
                }
                text->vfunc_3();
            }

            const char* name = file->FUN_00091d50();
            FUN_000964a0(frame.path, 0x100, "art/blonsky_file_images/%s.p3d", name);
            Loader_c1f70* loader = (Loader_c1f70*)FUN_00263ea0(0x14);
            if (loader)
                loader = loader->FUN_00266480(0x400);
            loader->init();
            FUN_000bc3c0(frame.path, loader, 0xb);
            FUN_000964a0(frame.image, 0x100, "%s.png", name);
            unsigned __int64 key = FUN_0027b020(frame.image);
            content::LoadInventory::DynamicCaster<pure3d::Texture> textureCaster;
            Resource_c1f70* tex = loader->find(&textureCaster, key);
            if (tex != 0) {
                Inventory_c1f70* inv = DAT_004dd9cc;
                unsigned __int64 key2 = FUN_0027b020("blonksy_image_shader");
                content::LoadInventory::DynamicCaster<pure3d::Shader> shaderCaster;
                ShaderHolder* shader = inv->find(&shaderCaster, key2);
                if (shader != 0)
                    shader->slot->set(0x584554, tex->f10);
            }
            loader->release();
        }
    }
    __security_check_cookie(cookie);
}
