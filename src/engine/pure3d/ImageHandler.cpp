// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00291bc0..0x00291c40 (kind game, layer engine, confidence high), dominant class pure3d::ImageHandler
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f2e8bf74 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f2e8bf74 {} using namespace fn_f2e8bf74;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f2e8bf74 {
class ImageHandler_291bc0 {
  public:
    ImageHandler_291bc0();
    virtual void FnF_00038290();
};
class PNGHandler : public ImageHandler_291bc0 {
  public:
    PNGHandler();
};


// 0x00291bc0 FUN_00291bc0 (18 B): matches/0x00291bc0.cpp
// sym: ??0PNGHandler@fn_f2e8bf74@@QAE@XZ
PNGHandler::PNGHandler() {}

} // namespace fn_f2e8bf74

// 0x00291be0 pure3d::ImageHandler::vfunc_10 (5 B): matches/0x00291be0.cpp
// sym: ?vfunc_10@ImageHandler@pure3d@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool pure3d::ImageHandler::vfunc_10(int , int ) {
    return false;
}


// 0x00291bf0 pure3d::ImageHandler::vfunc_11 (10 B): matches/0x00291bf0.cpp
// sym: ?vfunc_11@ImageHandler@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4b0 (propagated; names are from that function)
void pure3d::ImageHandler::vfunc_11(int value) {
    this->f_08 = value;
}

namespace fn_f2e8bf74 {

// 0x00291c00 pure3d::ImageHandler::vfunc_12 (4 B): matches/0x00291c00.cpp
// sym: ?FUN_00291c00@fn_f2e8bf74@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_00291c00(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_f2e8bf74

// 0x00291c10 pure3d::ImageHandler::vfunc_13 (10 B): matches/0x00291c10.cpp
// sym: ?vfunc_13@ImageHandler@pure3d@@UAEXE@Z
void pure3d::ImageHandler::vfunc_13(unsigned char value) {
    this->f_0c = value;
}


// 0x00291c20 pure3d::ImageHandler::vfunc_14 (4 B): matches/0x00291c20.cpp
// sym: ?vfunc_14@ImageHandler@pure3d@@UAEEXZ
// Same code shape as 0x0023b9b0 (propagated; names are from that function)
unsigned char pure3d::ImageHandler::vfunc_14() {
    return *(unsigned char*)((char*)this + 0xC);
}

namespace fn_f2e8bf74 {

// 0x00291c30 pure3d::ImageHandler::vfunc_15 (3 B): matches/0x00291c30.cpp
// sym: ?GetZero@fn_f2e8bf74@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f2e8bf74
