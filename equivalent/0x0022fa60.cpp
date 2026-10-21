// STATUS: equivalent (tools/equiv.py level 3: 15368 inputs, branch coverage 16/18, incomplete)
// FUN_0022fa60 @ 0x0022fa60
#include "compat/ptr.h"
struct Point_22fa60 { float x,y,z,w; };
struct Segment_22fa60 { char data[128]; void FUN_0022e670(unsigned int, Point_22fa60*, Point_22fa60*, Point_22fa60*, Point_22fa60*); };
// equiv-conv: FUN_0022f760 edi stack
extern "C" double __cdecl FUN_0022f760(Segment_22fa60*, float);
struct Curve_22fa60 {
 char pad[0x108]; unsigned char closed; char pad2[3]; unsigned int degree; unsigned int count; Point_22fa60* points;
 double FUN_0022f7e0(unsigned int);
 void FUN_0022ef20(unsigned int, float);
 hulk_freg FUN_0022fa60(float);
};
hulk_freg Curve_22fa60::FUN_0022fa60(float t) {
 if(t < 0.0f) t=0.0f;
 unsigned int limit=closed ? count : count-3;
 if((double)limit < t) t=(float)limit;
 unsigned int index=(unsigned int)(int)t;
 float sum=0.0f;
 for(unsigned int i=0;i<index;++i) sum=(float)(FUN_0022f7e0(i)+sum);
 FUN_0022ef20(0,t);
 unsigned int n=count; Point_22fa60* p=points;
 Segment_22fa60 segment;
 segment.FUN_0022e670(degree+3,p+(index%n),p+((index+1)%n),p+((index+2)%n),p+((index+3)%n));
 float fraction=(float)(t-(double)index);
 return (float)(FUN_0022f760(&segment,fraction)+sum);
}