// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// physics::PhysicsPropertiesLoader::vfunc_5 @ 0x002f2970
#include "compat/ptr.h"
#include "gen/physics.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "gen/owners.h"

typedef unsigned __int64 Key_2f2970;
struct Reader_2f2970 {  };
struct Context_2f2970 { char pad[0x284]; Reader_2f2970* reader; };
struct Manager_2f2970 { void FUN_002f27c0(Key_2f2970, float, float, float, float); };
namespace physics {

}
void physics::PhysicsPropertiesLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { Context_2f2970 * context = (Context_2f2970 *)__p2;

struct Data { char pad[3]; unsigned char length; float a,c,d,b; char name[256]; } data;
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.length), (hulk_intptr)1, 1, (hulk_intptr)1);
unsigned count=data.length;
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(data.name), (hulk_intptr)count, 1, (hulk_intptr)1);
data.name[count]=0;
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.a), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.b), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.d), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.a), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.c), (hulk_intptr)1, 4, (hulk_intptr)1);
float x=data.a*0.5f+1.0f, y=data.b+data.b, z=data.c*-1.0f, w=data.d+data.d;
Key_2f2970 key=FUN_0027b020(data.name);
(*(Manager_2f2970**)&DAT_00554c30)->FUN_002f27c0(key,x,y,z,w);
}
