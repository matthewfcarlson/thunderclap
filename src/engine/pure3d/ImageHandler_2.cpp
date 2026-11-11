// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002adda0..0x002adf20 (kind game, layer engine, confidence high), dominant class pure3d::ImageHandler::Builder
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f7f2e797 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f7f2e797 {} using namespace fn_f7f2e797;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f7f2e797 {
class ImageHandler_2adf00 {
  public:
    };

} // namespace fn_f7f2e797

// 0x002adda0 pure3d::ImageHandler::Builder::vfunc_7 (3 B): matches/0x002adda0.cpp
// sym: ?vfunc_7@Builder@ImageHandler@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::ImageHandler::Builder::vfunc_7(int a) {
    (void)a;
}


// 0x002addb0 FUN_002addb0 (88 B): matches/0x002addb0.cpp
// sym: ?FUN_002addb0@Transform_2addb0@owners@@QAEII@Z
unsigned int owners::Transform_2addb0::FUN_002addb0(unsigned int x) {
    return (((x & 0xff) >> r0) << s2) | (((x & 0xff0000) >> r1) << s0) | (((x & 0xff000000) >> r3) << s1) |
           (((x & 0xff00) >> r2) << s3);
}


// 0x002adec0 pure3d::ImageHandler::Builder::vfunc_3 (3 B): matches/0x002adec0.cpp
// sym: ?vfunc_3@Builder@ImageHandler@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::ImageHandler::Builder::vfunc_3(hulk_intptr a, int b) {}

namespace fn_f7f2e797 {

// 0x002aded0 pure3d::ImageHandler::Builder::vfunc_4 (3 B): matches/0x002aded0.cpp
// sym: ?GetZero@fn_f7f2e797@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f7f2e797

// 0x002adee0 pure3d::ImageHandler::Builder::vfunc_5 (3 B): matches/0x002adee0.cpp [wrapped: same definition as 0x002aded0 in this TU]
// sym: ?GetZero@fn_002adee0@@YAIXZ
namespace fn_002adee0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_002adee0


// 0x002adef0 pure3d::ImageHandler::Builder::vfunc_6 (3 B): matches/0x002adef0.cpp
// sym: ?vfunc_6@Builder@ImageHandler@pure3d@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void pure3d::ImageHandler::Builder::vfunc_6(int , int , int ) {}


// 0x002adf00 pure3d::ImageHandler::Builder::vfunc_8 (4 B): matches/0x002adf00.cpp
// sym: ?vfunc_8@Builder@ImageHandler@pure3d@@UAEHXZ
int pure3d::ImageHandler::Builder::vfunc_8() {
    return -1;
}


// 0x002adf10 pure3d::ImageHandler::Builder::vfunc_9 (3 B): matches/0x002adf10.cpp
// sym: ?vfunc_9@Builder@ImageHandler@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::ImageHandler::Builder::vfunc_9(int a) {
    (void)a;
}

