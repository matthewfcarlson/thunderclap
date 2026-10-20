// STATUS: equivalent (tools/equiv.py level 3: 341 inputs, branch coverage 21/22, incomplete)
// FUN_0022f7e0 @ 0x0022f7e0
#include "compat/ptr.h"
typedef unsigned int uint_22f7e0;
struct Point_22f7e0 { float x,y,z,w; };
struct Segment_22f7e0 {
 char data[0x80];
 void FUN_0022e670(uint_22f7e0, Point_22f7e0*, Point_22f7e0*, Point_22f7e0*, Point_22f7e0*);
};
// equiv-conv: FUN_0022f760 edi stack
float __cdecl FUN_0022f760(Segment_22f7e0*, float);
void* __cdecl FUN_0008d690(hulk_uintptr);
struct Curve_22f7e0 {
 char padding[0x108];
 unsigned char closed;
 char padding2[3];
 uint_22f7e0 degree;
 uint_22f7e0 count;
 Point_22f7e0* points;
 float* cache;
 void FUN_0022ef20(uint_22f7e0, float);
 float FUN_0022f7e0(uint_22f7e0 index);
};
float Curve_22f7e0::FUN_0022f7e0(uint_22f7e0 index) {
 uint_22f7e0 spans=count;
 if (!closed) spans=spans<4 ? 0 : spans-3;
 if(cache && cache[index]>=0.0f) return cache[index];
 if(!cache) {
  uint_22f7e0 size=spans+1;
  cache=(float*)FUN_0008d690(size*4);
  for(uint_22f7e0 i=0;i<size;++i) cache[i]=-1.0f;
 }
 FUN_0022ef20(0,(float)index);
 uint_22f7e0 n=count;
 Point_22f7e0* p=points;
 Segment_22f7e0 segment;
 segment.FUN_0022e670(degree+3,p+(index%n),p+((index+1)%n),p+((index+2)%n),p+((index+3)%n));
 cache[index]=FUN_0022f760(&segment,1.0f);
 return cache[index];
}
