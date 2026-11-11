// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00333370..0x003335e0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dShader
// (tree_prelude.h: not needed)


// 0x00333520 FUN_00333520 (147 B): equivalent/0x00333520.cpp [isolated: compile error C2039: 'FUN_00327e00' : is not a member of 'operator``global namespace''']
// sym: ??0d3dShader@pure3d@fn_00333520@@QAE@PAVd3dContext@1@@Z @d9d1a58a6614 @w68f26ac8d95e
#include "gen/pure3d.h"
namespace fn_00333520 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00333520 @ 0x00333520
// (x64t2) the owner is gen's d3dContext (its state cache f_150, a pointer, was read at a literal +0x150 into an int);
// the vftable stored by address (DAT_00433ffc: a local class's own would be the 64-bit link's stub)
extern "C" char DAT_00433ffc[];  // pure3d::d3dShader
struct FUN_00327e00 { void* vftable; char pad[12]; FUN_00327e00(); };  // pure3d::pddiBaseShader's constructor
namespace pure3d {
struct d3dShader : FUN_00327e00 {
 ::pure3d::d3dContext* owner; void* ownerValue;
 unsigned a18,a1c,a20,a24; unsigned char a28; char pad29[3];
 unsigned a2c; float a30,a34; unsigned a38,a3c,a40,a44;
 unsigned char a48; char pad49[3]; unsigned a4c,a50,a54,a58,a5c,a60,a64,a68,a6c,a70,a74; float a78; unsigned char a7c,a7d;
 d3dShader(::pure3d::d3dContext*);
};
d3dShader::d3dShader(::pure3d::d3dContext* p) {
 owner=p; vftable=DAT_00433ffc; ownerValue=p->f_150;
 a50=a54=a5c=a64=a68=a70=0xff000000;
 a3c=0; a48=0; a60=0; a18=0; a1c=0; a24=0; a28=0; a38=0; a7c=0; a7d=0;
 a40=1; a44=1; a4c=1; a58=0xffffffff; a6c=0xffffffff; a20=1; a2c=5; a30=0.5f; a34=0.5f; a78=127.998046875f;
}
}
} // namespace fn_00333520
