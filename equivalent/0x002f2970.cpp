// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::PhysicsPropertiesLoader::vfunc_5 @ 0x002f2970
#include "gen/physics.h"
#include "decls/address.h"

typedef unsigned __int64 Key_2f2970;
struct Reader_2f2970 { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Context_2f2970 { char pad[0x284]; Reader_2f2970* reader; };
struct Manager_2f2970 { void FUN_002f27c0(Key_2f2970, float, float, float, float); };
extern Manager_2f2970* DAT_00554c30;
namespace physics {

}
void physics::PhysicsPropertiesLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { Context_2f2970 * context = (Context_2f2970 *)__p2;

struct Data { char pad[3]; unsigned char length; float a,c,d,b; char name[256]; } data;
context->reader->FUN_002647e0(&data.length,1,1,1);
unsigned count=data.length;
context->reader->FUN_002647e0(data.name,count,1,1);
data.name[count]=0;
context->reader->FUN_002647e0(&data.a,1,4,1);
context->reader->FUN_002647e0(&data.b,1,4,1);
context->reader->FUN_002647e0(&data.d,1,4,1);
context->reader->FUN_002647e0(&data.a,1,4,1);
context->reader->FUN_002647e0(&data.c,1,4,1);
float x=data.a*0.5f+1.0f, y=data.b+data.b, z=data.c*-1.0f, w=data.d+data.d;
Key_2f2970 key=FUN_0027b020(data.name);
DAT_00554c30->FUN_002f27c0(key,x,y,z,w);
}
