// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ddbe0..0x002ddfb0 (kind game, layer engine, confidence medium), dominant class pure3d::RawImageHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fc34c861 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fc34c861 {} using namespace fn_fc34c861;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fc34c861 {
class Ref_2ddbe0 {
  public:
    virtual void F();
};
class Owner_2ddbe0 {
  public:
    Ref_2ddbe0* mRef;
    Owner_2ddbe0* Set(Ref_2ddbe0* r);
};
class Item_2ddc00 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_2ddc00 {
  public:
    Item_2ddc00* mItem;
    Item_2ddc00* Set(Item_2ddc00* item);
};
struct Stream_2ddf10 {
};
struct Image_2ddf10 {
    virtual void SetFormat(unsigned int a, unsigned int b, unsigned int c, int d, int e);   // slot 0
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void *GetPixels();                                                              // slot 4
    virtual void *GetPalette();                                                             // slot 5
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Finish();                                                                  // slot 10
};
struct RawHeader {
    unsigned int magic;
    unsigned int words[6];
};


// 0x002ddbe0 FUN_002ddbe0 (23 B): matches/0x002ddbe0.cpp
// sym: ?Set@Owner_2ddbe0@fn_fc34c861@@QAEPAV12@PAVRef_2ddbe0@2@@Z
// Same code shape as 0x001b75d0 (propagated; names are from that function)
Owner_2ddbe0* Owner_2ddbe0::Set(Ref_2ddbe0* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}


// 0x002ddc00 FUN_002ddc00 (42 B): matches/0x002ddc00.cpp
// sym: ?Set@Holder_2ddc00@fn_fc34c861@@QAEPAVItem_2ddc00@2@PAV32@@Z
// Same code shape as 0x001b7620 (propagated; names are from that function)
Item_2ddc00* Holder_2ddc00::Set(Item_2ddc00* item) {
    Item_2ddc00* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}

} // namespace fn_fc34c861

// 0x002ddee0 pure3d::RawImageHandler::vfunc_8 (29 B): matches/0x002ddee0.cpp
// sym: ?vfunc_8@RawImageHandler@pure3d@@UAE_NH@Z
bool pure3d::RawImageHandler::vfunc_8(int x) {
    if (x >= 11 && (x <= 19 || x == 23))
        return (bool)(1);
    return (bool)(0);
}


// 0x002ddf10 pure3d::RawImageHandler::vfunc_9 (145 B): matches/0x002ddf10.cpp
// sym: ?vfunc_9@RawImageHandler@pure3d@@UAEXHH@Z
// pure3d::RawImageHandler::vfunc_9 @ 0x002ddf10
void pure3d::RawImageHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { Stream_2ddf10 * stream = (Stream_2ddf10 *)__p0; Image_2ddf10 * image = (Image_2ddf10 *)__p1;

    RawHeader hdr;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)(&hdr), (hulk_intptr)7, 4, (hulk_intptr)1);
    if (hdr.magic != 0x49443350)    // "P3DI"
        return;

    image->SetFormat(hdr.words[1], hdr.words[2], hdr.words[3], 0, 0);
    if (hdr.words[4] > 0) {
        void *palette = image->GetPalette();
        if (palette != 0)
            ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)palette, (hulk_intptr)(hdr.words[4]), 1, (hulk_intptr)1);
    }
    void *pixels = image->GetPixels();
    if (pixels != 0)
        ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)pixels, (hulk_intptr)(hdr.words[5]), 1, (hulk_intptr)1);
    image->Finish();
}

