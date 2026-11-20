// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273c70..0x00273d50 (kind game, layer engine, confidence medium), dominant class core::SaveGameOpenRequest
#include "tree_prelude.h"
#include "decls/data/records.h"
#include "decls/save_game.h"
#include "compat/ptr.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f1bb87c2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1bb87c2 {} using namespace fn_f1bb87c2;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f1bb87c2 {
struct Sub_273c70 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_273c70 {
    void* v;
    Sub_273c70 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273c70 {
    void* v;
    char pad[4];
    Inner_273c70* p;
    void run();
};
// (drive1, D141) the drive's media block (decls/drive_media.h; 0x002728d0 returns it): its sector size
typedef CoreDriveMedia Info_273cb0;
// the drive's slot 9 (XboxSaveDrive::vfunc_9 0x00279630): the save's name and image are pointers, and so are the
// words it fills, the file's handle (its view's tail[1]) and its size (field128)
struct Backend_273cb0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual int open(const char*,unsigned,unsigned,GameSaveImage*,unsigned,unsigned*,unsigned*);
 unsigned FUN_00272880();
};
struct Lock_273cb0 { virtual void lock(); virtual void unlock(); };
class pddiObject_273d40 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_273d40 : public pddiObject_273d40 {};
class pddiBaseShader_273d40 : public pddiShader_273d40 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_273d40 : public pddiBaseShader_273d40 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};


// 0x00273c70 FUN_00273c70 (53 B): matches/0x00273c70.cpp
// sym: ?run@FileRequest_273c70@fn_f1bb87c2@@QAEXXZ
void FileRequest_273c70::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    ((Sub_273c70*)&((CoreFile*)p)->vftableMutable)->f();
    --((CoreFile*)p)->field18;
    ((Sub_273c70*)&((CoreFile*)p)->vftableMutable)->g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}

} // namespace fn_f1bb87c2

// 0x00273cb0 core::SaveGameOpenRequest::vfunc_1 (129 B): equivalent/0x00273cb0.cpp
// sym: ?vfunc_1@SaveGameOpenRequest@core@@UAEHXZ @59bdffe1a33c @wba1ea125a2bf @v38220eded086
// STATUS: equivalent (tools/equiv.py level 3: 19867 inputs, branch coverage 2/2)
// core::SaveGameOpenRequest::vfunc_1 @ 0x00273cb0
int core::SaveGameOpenRequest::vfunc_1() {
 // (drive1, D141) the request is decls/save_game.h CoreSaveGameOpenRequest and its file records.h CoreFile (were
 // 32-bit views: natively the open's arguments were read from the file pointer's words and the image truncated)
 CoreSaveGameOpenRequest* request = (CoreSaveGameOpenRequest*)this;
 CoreFile* s = (CoreFile*)request->request.file;
 Backend_273cb0* backend = (Backend_273cb0*)s->provider;
 int result = backend->open(s->filename,request->mode,request->writable,request->image,request->size,&s->view.tail[1],&s->field128);
 if(result == 1) {
 ((CoreFile*)request->request.file)->flag1c = 1;
 Info_273cb0* info = ((Info_273cb0 *)((owners::ProjectileMissile_2728d0 *)backend)->FUN_002728d0());
 ((CoreFile*)request->request.file)->field164 = info->sectorSize;
 }
 unsigned status = backend->FUN_00272880();
 ((Lock_273cb0*)&((CoreFile*)request->request.file)->vftableMutable)->lock();
 ((CoreFile*)request->request.file)->field14 = status;
 ((Lock_273cb0*)&((CoreFile*)request->request.file)->vftableMutable)->unlock();
 return result;
}


// 0x00273d40 core::SaveGameOpenRequest::vfunc_6 (6 B): matches/0x00273d40.cpp
// sym: ?vfunc_6@SaveGameOpenRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::SaveGameOpenRequest::vfunc_6() {
    return 1;
}

