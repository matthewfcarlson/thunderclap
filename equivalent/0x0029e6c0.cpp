// STATUS: equivalent (tools/equiv.py level 3: 18165 inputs, branch coverage 8/8)
// FUN_0029e6c0 @ 0x0029e6c0
#include "decls/data/engine/unknown.h"

extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct Entry_29e6c0 {
 unsigned char active; char pad[3];
 unsigned int a; int index; unsigned int c,d,e,f,g;
 float x,y;
 unsigned int h,i,j,k,l;
 float limit;
};
struct FUN_0027b070 {
 virtual void placeholder();
 char pad[12];
 FUN_0027b070();
};
namespace pure3d {
struct LightsChooserCache : FUN_0027b070 {
 int count; unsigned int f14,f18; int f1c; float f20; Entry_29e6c0* entries;
 unsigned int f28,f2c,f30,color;
 unsigned char flag; char pad38[3]; unsigned int f3c,f40;
 virtual void placeholder();
 LightsChooserCache(int);
};
LightsChooserCache::LightsChooserCache(int n) {
 count=n; f14=0; f18=0; f1c=-1; f20=0.001f;
 entries=0; f28=0; f2c=0; f30=0;
 f3c=1; f40=1; color=(*(unsigned int*)&DAT_004cf730); flag=0;
 int size=count>0?count:0;
 count=size;
 Entry_29e6c0* p=(Entry_29e6c0*)FUN_0008d6d0((unsigned int)size*64);
 if(p) {
 for(int t=0;t<size;++t) {
 p[t].active=0; p[t].a=0; p[t].index=-1; p[t].c=0;p[t].d=0;p[t].e=0;p[t].f=0;p[t].g=0;
 p[t].x=1.0f;p[t].y=1.0f;p[t].h=0;p[t].i=0;p[t].j=0;p[t].k=0;p[t].l=0;p[t].limit=10000000.0f;
 }
 }
 entries=p;
}
}