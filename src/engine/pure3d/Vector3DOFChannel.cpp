// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028a780..0x0028a8e0 (kind game, layer engine, confidence medium), dominant class pure3d::Vector3DOFChannel
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f664d060 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f664d060 {} using namespace fn_f664d060;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f664d060 {
struct V3_28a780 {
    int x, y, z;
};
} // namespace fn_f664d060
namespace pure3d {
struct Vector_28a7c0 { float x,y,z; };
}
namespace pure3d {
struct Vector3DOFChannel_nv_28a7c0 {
    bool FUN_00289f80(float time, int* first, int* second);
};
}


// 0x0028a780 pure3d::Vector3DOFChannel::vfunc_3 (58 B): matches/0x0028a780.cpp
// sym: ?vfunc_3@Vector3DOFChannel@pure3d@@UAEXHPAX0@Z
void pure3d::Vector3DOFChannel::vfunc_3(int index, void* __p1, void* __p2) { float * outIndex = (float *)__p1; V3_28a780 * outValue = (V3_28a780 *)__p2;

    *outIndex = (float)(*(short * *)&this->f_14)[index];
    V3_28a780* p = (*(V3_28a780 * *)&this->f_18) + index;
    int a = p->x;
    V3_28a780* q = p;
    outValue->x = a;
    outValue->y = q->y;
    outValue->z = q->z;
}


// 0x0028a7c0 pure3d::Vector3DOFChannel::vfunc_4 (274 B): equivalent/0x0028a7c0.cpp
// sym: ?vfunc_4@Vector3DOFChannel@pure3d@@UAEXMH@Z @3d01cb3a70dc @wbf6b2de9fa4b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// pure3d::Vector3DOFChannel::vfunc_4 @ 0x0028a7c0
void pure3d::Vector3DOFChannel::vfunc_4(float time, hulk_intptr __p1) { Vector_28a7c0 * out = (Vector_28a7c0 *)__p1;

 int first, second;
 bool found = ((Vector3DOFChannel_nv_28a7c0*)this)->FUN_00289f80(time, &first, &second);
 if (found && this->f_04) {
  double delta = (double)time - (*(short * *)&this->f_14)[first];
  if (delta != 0.0) {
   double t = delta / (int)((*(short * *)&this->f_14)[second] - (*(short * *)&this->f_14)[first]);
   out->x = (float)(((double)(*(Vector_28a7c0 * *)&this->f_18)[second].x - (*(Vector_28a7c0 * *)&this->f_18)[first].x) * t + (*(Vector_28a7c0 * *)&this->f_18)[first].x);
   out->y = (float)(((double)(*(Vector_28a7c0 * *)&this->f_18)[second].y - (*(Vector_28a7c0 * *)&this->f_18)[first].y) * t + (*(Vector_28a7c0 * *)&this->f_18)[first].y);
   out->z = (float)(((double)(*(Vector_28a7c0 * *)&this->f_18)[second].z - (*(Vector_28a7c0 * *)&this->f_18)[first].z) * t + (*(Vector_28a7c0 * *)&this->f_18)[first].z);
   return;
  }
 }
 *out = (*(Vector_28a7c0 * *)&this->f_18)[first];
}

