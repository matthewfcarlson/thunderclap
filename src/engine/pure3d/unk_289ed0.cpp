// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00289ed0..0x0028a3a0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ffa7c92d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ffa7c92d {} using namespace fn_ffa7c92d;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ffa7c92d {
class Obj_289ed0 {
  public:
    Obj_289ed0* Get();
};
class X_289ee0 {
  public:
    X_289ee0* Fn();
};
class T_289ef0 {
  public:
    T_289ef0* Init();
};
class SimpleChannel_28a180 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned int vfunc_2();
};
struct Pair_28a2c0 { float x,y; };
struct Track {
 char pad0[4]; int enabled; char pad8[12]; short* times; Pair_28a2c0* values;
 void FUN_0028a2c0(float time,Pair_28a2c0* out);
};


// 0x00289ed0 FUN_00289ed0 (3 B): matches/0x00289ed0.cpp
// sym: ?Get@Obj_289ed0@fn_ffa7c92d@@QAEPAV12@XZ
Obj_289ed0* Obj_289ed0::Get() {
    return this;
}


// 0x00289ee0 FUN_00289ee0 (3 B): matches/0x00289ee0.cpp
// sym: ?Fn@X_289ee0@fn_ffa7c92d@@QAEPAV12@XZ
X_289ee0* X_289ee0::Fn() {
    return this;
}


// 0x00289ef0 FUN_00289ef0 (3 B): matches/0x00289ef0.cpp
// sym: ?Init@T_289ef0@fn_ffa7c92d@@QAEPAV12@XZ
T_289ef0* T_289ef0::Init() {
    return this;
}


// 0x00289f70 pure3d::Channel::vfunc_1 (1 B): matches/0x00289f70.cpp
// sym: ?FUN_00289f70@fn_ffa7c92d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00289f70() {}

} // namespace fn_ffa7c92d

// 0x00289f80 FUN_00289f80 (225 B): equivalent/0x00289f80.cpp
// sym: ?FUN_00289f80@Table_289f80@owners@@QAE_NMPAH0@Z
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 11/12, incomplete)
// FUN_00289f80 @ 0x00289f80
bool owners::Table_289f80::FUN_00289f80(float value, int* lower, int* upper) {
 short* data = values;
 if (!((float)data[0] < value)) { *upper = 0; *lower = 0; return false; }
 int n = count;
 if ((float)data[n-1] <= value) { *upper = n-1; *lower = n-1; return false; }
 unsigned int lo = 0, hi = n-1;
 for (;;) {
  unsigned int mid = (lo + hi) >> 1;
  float current = (float)data[mid];
  if (value >= current && (float)data[mid+1] > value) {
   *lower = mid;
   *upper = mid+1;
   return true;
  }
  if (current < value) lo = mid+1;
  else if (current > value) hi = mid-1;
 }
}

namespace fn_ffa7c92d {

// 0x0028a070 pure3d::IntChannel::vfunc_2 (6 B): matches/0x0028a070.cpp
// sym: _FUN_0028a070
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0028a070() {
    return (int*)0x544e49;
}

} // namespace fn_ffa7c92d

// 0x0028a080 FUN_0028a080 (40 B): matches/0x0028a080.cpp
// sym: ?FUN_0028a080@X_28a080@owners@@QAEXHPAMPAH@Z
void owners::X_28a080::FUN_0028a080(int i, float* out, int* out2) {
    *out = (float)a[i];
    *out2 = b[i];
}


// 0x0028a0b0 FUN_0028a0b0 (203 B): equivalent/0x0028a0b0.cpp
// sym: ?FUN_0028a0b0@Track_28a0b0@owners@@QAEXMPAH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 6/6)
// FUN_0028a0b0 @ 0x0028a0b0
void owners::Track_28a0b0::FUN_0028a0b0(float time, int* result) {
    int first, second;
    bool found = FUN_00289f80(time, &first, &second);
    if (!found || !interpolate) {
        *result = values[first];
        return;
    }
    double delta = (double)time - (int)(__int64)times[first];
    if (delta == 0.0f) {
        *result = values[first];
        return;
    }
    int base = values[first];
    int difference = (int)(__int64)((unsigned int)(__int64)values[second] - (unsigned int)(__int64)base);
    int duration = (int)(__int64)times[second] - (int)(__int64)times[first];
    int step = (int)(__int64)(((double)difference / duration) * delta);
    *result = (int)(__int64)((unsigned int)(__int64)base + (unsigned int)(__int64)step);
}


// 0x0028a180 pure3d::Float1Channel::vfunc_2 (6 B): matches/0x0028a180.cpp
// sym: ?vfunc_2@Float1Channel@pure3d@@UAEIXZ
unsigned int pure3d::Float1Channel::vfunc_2() {
    return 0x31544c46;
}


// 0x0028a1c0 FUN_0028a1c0 (176 B): equivalent/0x0028a1c0.cpp
// sym: ?FUN_0028a1c0@Curve_28a1c0@owners@@QAEXMPAM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0028a1c0 @ 0x0028a1c0
void owners::Curve_28a1c0::FUN_0028a1c0(float time, float* output) {
    int first, second;
    if (FUN_00289f80(time, &first, &second) && enabled) {
        double delta = (double)time - times[first];
        if (delta != 0.0f) {
            *output = (float)(((double)values[second] - values[first]) / (times[second] - times[first]) * delta + values[first]);
            return;
        }
    }
    *output = values[first];
}


// 0x0028a270 pure3d::Float2Channel::vfunc_2 (6 B): matches/0x0028a270.cpp
// sym: ?vfunc_2@Float2Channel@pure3d@@UAEIXZ
unsigned int pure3d::Float2Channel::vfunc_2() {
    return 0x32544c46;
}

namespace fn_ffa7c92d {

// 0x0028a2c0 FUN_0028a2c0 (221 B): equivalent/0x0028a2c0.cpp
// sym: ?FUN_0028a2c0@Track@fn_ffa7c92d@@QAEXMPAUPair_28a2c0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0028a2c0 @ 0x0028a2c0
void Track::FUN_0028a2c0(float time,Pair_28a2c0* out) {
 int first,second;
 if (!((owners::Table_289f80 *)this)->FUN_00289f80(time, &first, &second) || !enabled) {
 Pair_28a2c0* source=values;
 out->x=source[first].x;
 out->y=source[first].y;
 return;
 }
 double delta=(double)time-times[first];
 if (delta == 0.0f) {
 Pair_28a2c0* source=values;
 out->x=source[first].x;
 out->y=source[first].y;
 return;
 }
 double ratio=delta/(int)(times[second]-times[first]);
 Pair_28a2c0* source=values;
 out->x=(float)(((double)source[second].x-source[first].x)*ratio+source[first].x);
 source=values;
 out->y=(float)(((double)source[second].y-source[first].y)*ratio+source[first].y);
}

} // namespace fn_ffa7c92d
