// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fa7c0 @ 0x002fa7c0
#include "decls/data/game/global.h"

struct Vec_2fa7c0 { float x,y,z; };
struct Mesh_2fa7c0 { char pad[8]; Vec_2fa7c0* vertices; char pad2[12]; char* faces; };
struct Context { char pad[0x44]; Mesh_2fa7c0* mesh; };
struct Shape_2fa7c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(); char pad[0x24]; char data[1]; };
void __cdecl FUN_002fa6b0(Vec_2fa7c0*,Vec_2fa7c0*,Vec_2fa7c0*,Vec_2fa7c0*);
bool __cdecl FUN_0035a4c0(int,void*,Vec_2fa7c0*,Vec_2fa7c0*,Vec_2fa7c0*,Vec_2fa7c0*,float*,Vec_2fa7c0*,Vec_2fa7c0*,bool,bool,bool);
struct Manager_2fa7c0 { void FUN_00304530(Shape_2fa7c0*,unsigned,float,Vec_2fa7c0*,Vec_2fa7c0*,Context*,int); };
struct Global_2fa7c0 { char pad[0x1b0]; Manager_2fa7c0 manager; };
struct Face_2fa7c0 { char pad[0x10]; unsigned short a,b,c,flags; bool run(Shape_2fa7c0*,Context*,int); };
bool Face_2fa7c0::run(Shape_2fa7c0* shape,Context* context,int arg) {
 Vec_2fa7c0* vertices=context->mesh->vertices;
 Vec_2fa7c0* p0=vertices+a; Vec_2fa7c0* p1=vertices+b; Vec_2fa7c0* p2=vertices+c;
 Vec_2fa7c0 normal,outA,outB; float value;
 FUN_002fa6b0(p0,p1,p2,&normal);
 bool f0=(flags&1)!=0, f1=(flags&2)!=0, f2=(flags&4)!=0;
 bool result=FUN_0035a4c0(shape->v4(),shape->data,p0,p1,p2,&normal,&value,&outB,&outA,f0,f1,f2);
 if(result) {
 unsigned index=(unsigned)((char*)this-context->mesh->faces)/24;
 (*(Global_2fa7c0**)&DAT_00554c14)->manager.FUN_00304530(shape,index,value,&outB,&outA,context,arg);
 }
 return result;
}