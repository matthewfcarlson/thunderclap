// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fa7c0 @ 0x002fa7c0
struct Vec { float x,y,z; };
struct Mesh { char pad[8]; Vec* vertices; char pad2[12]; char* faces; };
struct Context { char pad[0x44]; Mesh* mesh; };
struct Shape { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(); char pad[0x24]; char data[1]; };
void __cdecl FUN_002fa6b0(Vec*,Vec*,Vec*,Vec*);
bool __cdecl FUN_0035a4c0(int,void*,Vec*,Vec*,Vec*,Vec*,float*,Vec*,Vec*,bool,bool,bool);
struct Manager { void FUN_00304530(Shape*,unsigned,float,Vec*,Vec*,Context*,int); };
struct Global { char pad[0x1b0]; Manager manager; };
extern Global* DAT_00554c14;
struct Face { char pad[0x10]; unsigned short a,b,c,flags; bool run(Shape*,Context*,int); };
bool Face::run(Shape* shape,Context* context,int arg) {
 Vec* vertices=context->mesh->vertices;
 Vec* p0=vertices+a; Vec* p1=vertices+b; Vec* p2=vertices+c;
 Vec normal,outA,outB; float value;
 FUN_002fa6b0(p0,p1,p2,&normal);
 bool f0=(flags&1)!=0, f1=(flags&2)!=0, f2=(flags&4)!=0;
 bool result=FUN_0035a4c0(shape->v4(),shape->data,p0,p1,p2,&normal,&value,&outB,&outA,f0,f1,f2);
 if(result) {
 unsigned index=(unsigned)((char*)this-context->mesh->faces)/24;
 DAT_00554c14->manager.FUN_00304530(shape,index,value,&outB,&outA,context,arg);
 }
 return result;
}