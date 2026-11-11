// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028a4a0..0x0028a5b0 (kind game, layer engine, confidence medium), dominant class pure3d::Vector1DOFChannel
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f832bf6d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f832bf6d {} using namespace fn_f832bf6d;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace pure3d {
struct Vector_28a4e0 { float x,y,z; };
}
namespace pure3d {
struct Vector1DOFChannel_nv_28a4e0 {
    bool FUN_00289f80(float time, int* first, int* second);
};
}


// 0x0028a4a0 pure3d::Vector1DOFChannel::vfunc_3 (63 B): matches/0x0028a4a0.cpp
// sym: ?vfunc_3@Vector1DOFChannel@pure3d@@UAEXHPAX0@Z
void pure3d::Vector1DOFChannel::vfunc_3(int index, void* __p1, void* __p2) { float * out = (float *)__p1; unsigned int * vec = (unsigned int *)__p2;

    *out = (float)(int)(*(short * *)&this->f_14)[index];
    vec[0] = this->f_1c;
    vec[1] = this->f_20;
    vec[2] = this->f_24;
    vec[this->f_18] = (*(unsigned int * *)&this->f_28)[index];
}


// 0x0028a4e0 pure3d::Vector1DOFChannel::vfunc_4 (195 B): equivalent/0x0028a4e0.cpp
// sym: ?vfunc_4@Vector1DOFChannel@pure3d@@UAEXMH@Z @440d280ead01 @wfb95e7521237
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 6/6)
// pure3d::Vector1DOFChannel::vfunc_4 @ 0x0028a4e0
void pure3d::Vector1DOFChannel::vfunc_4(float time, hulk_intptr __p1) { Vector_28a4e0 * out = (Vector_28a4e0 *)__p1;

 out->x=(*(Vector_28a4e0 *)&this->f_1c).x; out->y=(*(Vector_28a4e0 *)&this->f_1c).y; out->z=(*(Vector_28a4e0 *)&this->f_1c).z;
 int first, second;
 if (((Vector1DOFChannel_nv_28a4e0*)this)->FUN_00289f80(time,&first,&second) && this->f_04) {
  double delta=(double)time-(int)(*(short * *)&this->f_14)[first];
  if(delta==0.0f) { (&out->x)[this->f_18]=(*(float * *)&this->f_28)[first]; return; }
  (&out->x)[this->f_18]=(float)(((double)(*(float * *)&this->f_28)[second]-(*(float * *)&this->f_28)[first])/((int)(*(short * *)&this->f_14)[second]-(int)(*(short * *)&this->f_14)[first])*delta+(*(float * *)&this->f_28)[first]);
 } else { (&out->x)[this->f_18]=(*(float * *)&this->f_28)[first]; }
}

