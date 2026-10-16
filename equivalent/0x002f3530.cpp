// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 2/2)
// FUN_002f3530 @ 0x002f3530
#include "decls/address.h"
#include "decls/data/engine/physics.h"
typedef unsigned int uint;
  
void* __cdecl operator new(unsigned int);
extern void* __cdecl FUN_002f2750(unsigned __int64);
struct Matrix { char bytes[64]; void FUN_0022b980(); };
struct FUN_003060a0 { virtual void baseVirtual(); char bytes[52]; FUN_003060a0(); };
namespace physics {
struct CollisionMesh : FUN_003060a0 {
 virtual void meshVirtual();
 uint a,b,c;
 struct SharedData {
 virtual void initialize();
 uint a,b; char pad[8]; uint c,d; unsigned short e,f,g; char tail[50];
 };
 SharedData* shared; void* material; Matrix m1,m2;
 unsigned char flag; char pad[3]; uint id;
 CollisionMesh();
};
}
physics::CollisionMesh::CollisionMesh() {
 a=0;b=0;c=0;flag=0;
 (*(void**)&DAT_0055543c)=((char*)((char*)&DAT_00554c30 + 2056)); (*(void**)&DAT_00555440)=((char*)((char*)&DAT_00554c30 + 8));
 SharedData* p=new SharedData;
 if(p) { p->a=0;p->b=0;p->c=0;p->d=0;p->e=0;p->f=0;p->g=0; }
 shared=p; shared->initialize();
 material=FUN_002f2750(FUN_0027b020("concrete"));
 m1.FUN_0022b980(); m2.FUN_0022b980();
 id=(*(uint*)&DAT_00555448)+0x3d70000; (*(uint*)&DAT_00555448)=id;
}
