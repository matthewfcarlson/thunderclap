// STATUS: equivalent (tools/equiv.py level 3: 602 inputs, branch coverage 16/18, incomplete)
// FUN_0022fa60 @ 0x0022fa60
struct Point { float x,y,z,w; };
struct Segment { char data[128]; void FUN_0022e670(unsigned int, Point*, Point*, Point*, Point*); };
// equiv-conv: FUN_0022f760 edi stack
extern "C" double __cdecl FUN_0022f760(Segment*, float);
struct Curve {
 char pad[0x108]; unsigned char closed; char pad2[3]; unsigned int degree; unsigned int count; Point* points;
 double FUN_0022f7e0(unsigned int);
 void FUN_0022ef20(unsigned int, float);
 float FUN_0022fa60(float);
};
float Curve::FUN_0022fa60(float t) {
 if(t < 0.0f) t=0.0f;
 unsigned int limit=closed ? count : count-3;
 if((double)limit < t) t=(float)limit;
 unsigned int index=(unsigned int)(int)t;
 float sum=0.0f;
 for(unsigned int i=0;i<index;++i) sum=(float)(FUN_0022f7e0(i)+sum);
 FUN_0022ef20(0,t);
 unsigned int n=count; Point* p=points;
 Segment segment;
 segment.FUN_0022e670(degree+3,p+(index%n),p+((index+1)%n),p+((index+2)%n),p+((index+3)%n));
 float fraction=(float)(t-(double)index);
 return (float)(FUN_0022f760(&segment,fraction)+sum);
}