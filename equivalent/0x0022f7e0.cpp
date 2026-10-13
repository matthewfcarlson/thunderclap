// STATUS: equivalent (tools/equiv.py level 3: 341 inputs, branch coverage 21/22, incomplete)
// FUN_0022f7e0 @ 0x0022f7e0
typedef unsigned int uint;
struct Point { float x,y,z,w; };
struct Segment {
 char data[0x80];
 void FUN_0022e670(uint, Point*, Point*, Point*, Point*);
};
// equiv-conv: FUN_0022f760 edi stack
float __cdecl FUN_0022f760(Segment*, float);
void* __cdecl FUN_0008d690(uint);
struct Curve {
 char padding[0x108];
 unsigned char closed;
 char padding2[3];
 uint degree;
 uint count;
 Point* points;
 float* cache;
 void FUN_0022ef20(uint, float);
 float FUN_0022f7e0(uint index);
};
float Curve::FUN_0022f7e0(uint index) {
 uint spans=count;
 if (!closed) spans=spans<4 ? 0 : spans-3;
 if(cache && cache[index]>=0.0f) return cache[index];
 if(!cache) {
  uint size=spans+1;
  cache=(float*)FUN_0008d690(size*4);
  for(uint i=0;i<size;++i) cache[i]=-1.0f;
 }
 FUN_0022ef20(0,(float)index);
 uint n=count;
 Point* p=points;
 Segment segment;
 segment.FUN_0022e670(degree+3,p+(index%n),p+((index+1)%n),p+((index+2)%n),p+((index+3)%n));
 cache[index]=FUN_0022f760(&segment,1.0f);
 return cache[index];
}
