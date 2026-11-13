// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c0be0..0x002c0cf0 (kind game, layer engine, confidence medium), dominant class pure3d::ImageLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f2c92ace {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f2c92ace {} using namespace fn_f2c92ace;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f2c92ace {
extern "C" char DAT_0042eb0c[];
typedef unsigned int u32_2c0be0;
struct Obj_2c0be0 {
    void ReleaseThing_002ae910();
};
// (x64t8) the loader's record (decls/loaders.h HulkImageLoader), shared with the sources that allocate it
class ImageLoader : public HulkImageLoader {
  public:
    void Destroy();
};
void __cdecl DropThing_0008d330(Obj_2c0be0*);
} // namespace fn_f2c92ace
namespace pure3d {
struct ImageData {
    char pad[8];
    unsigned int width;
    unsigned int height;
};
}
namespace pure3d {
struct ImageLoader_nv_2c0c10 {
    ImageData* FUN_002c0590(hulk_uintptr data, unsigned int format);
};
}
namespace fn_f2c92ace {
class Sub_2c0c40 {
  public:
    void* Init_002af2d0();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (x64t7) the allocator (was the placeholder `alloc`, unbound natively)


// 0x002c0be0 FUN_002c0be0 (42 B): matches/0x002c0be0.cpp
// sym: ?Destroy@ImageLoader@fn_f2c92ace@@QAEXXZ
void ImageLoader::Destroy() {
    Obj_2c0be0* p = (Obj_2c0be0*)registry;
    vftable = (void*)DAT_0042eb0c;
    if (p) {
        p->ReleaseThing_002ae910();
        DropThing_0008d330(p);
    }
    vftable = (void*)DAT_003f6098;
}

} // namespace fn_f2c92ace

// 0x002c0c10 pure3d::ImageLoader::vfunc_5 (42 B): matches/0x002c0c10.cpp
// sym: ?vfunc_5@ImageLoader@pure3d@@UAEXPAX00H@Z
 // namespace pure3d
void pure3d::ImageLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { ImageData ** image = (ImageData **)__p0; unsigned int * size = (unsigned int *)__p1; hulk_uintptr data = (hulk_uintptr)__p2; unsigned int unused = (unsigned int)__p3;

    ImageData* loaded = ((ImageLoader_nv_2c0c10*)this)->FUN_002c0590(data, (*(unsigned int *)&this->f_18));
    if (loaded) {
        *image = loaded;
        size[0] = loaded->width;
        size[1] = loaded->height;
    }
}

namespace fn_f2c92ace {

// 0x002c0c40 FUN_002c0c40 (84 B): matches/0x002c0c40.cpp
// sym: ?FUN_002c0c40@fn_f2c92ace@@YIPAXPAVImageLoader@1@@Z
void* __fastcall FUN_002c0c40(ImageLoader* p) {
    p->refs = 0;
    p->id = 0x19001;
    p->f0c = 0;
    p->f10 = 0;
    p->vftable = (void*)DAT_0042eb0c;
    p->f18 = 0x20;
    Sub_2c0c40* s = (Sub_2c0c40*)FUN_0008d690(sizeof(FUN_002af2d0));   // (x64t8) the image registry (0x002af2d0) at its record's size
    FUN_002af2d0* r;
    if (s)
        r = (FUN_002af2d0*)s->Init_002af2d0();
    else
        r = 0;
    p->registry = r;
    return p;
}

} // namespace fn_f2c92ace

// 0x002c0ca0 pure3d::ImageLoader::vfunc_2 (62 B): matches/0x002c0ca0.cpp [wrapped: conflict: ImageLoader]
// sym: ?f2@ImageLoader@fn_002c0ca0@@QAEPAV12@E@Z
namespace fn_002c0ca0 {
extern char hulk_at_0042eb0c[];
extern char hulk_at_003f6098[];
class Helper_2c0ca0 {
  public:
    void cleanup_002ae910();
};
void destroy_0008d330(void*);
void destroyThis_00263f30(void*);
class ImageLoader {
  public:
    void* vptr;
    char pad[0x10];
    Helper_2c0ca0* mPtr;
    ImageLoader* f2(unsigned char p);
};
ImageLoader* ImageLoader::f2(unsigned char p) {
    Helper_2c0ca0* h = mPtr;
    vptr = hulk_at_0042eb0c;
    if (h) {
        h->cleanup_002ae910();
        destroy_0008d330(h);
    }
    vptr = hulk_at_003f6098;
    if (p & 1)
        destroyThis_00263f30(this);
    return this;
}
} // namespace fn_002c0ca0

