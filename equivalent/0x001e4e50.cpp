// STATUS: equivalent (tools/equiv.py level 3: 406 inputs, branch coverage 20/20)
// FUN_001e4e50 @ 0x001e4e50
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
struct State_1e4e50 { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Player_1e4e50 { char pad[0x80]; State_1e4e50 state; };
struct Manager_1e4e50 {  };
struct World { char pad[0x54]; Manager_1e4e50* manager; };
struct Random_1e4e50 { float FUN_000787e0(float,float); };
struct Vec_1e4e50 { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022b980();   };
extern void* __cdecl FUN_001d68e0(int);
struct CSPManager_1e4e50 { void FUN_001e4c40(void*,Vec_1e4e50*,int,int,Vec_1e4e50*,int); void target(int,float,float,float,float,int); };
void CSPManager_1e4e50::target(int type,float x,float y,float z,float scale,int count) {
 int active=((Player_1e4e50 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->state.FUN_00088fa0();
 int mode=((Player_1e4e50 *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310())->state.FUN_00088fb0();
 if(active==0 && (mode==1 || mode==10) && (type==1 || type==2 || type==3 || type==4)) return;
 void* resource=FUN_001d68e0(type);
 if(!resource) return;
 Vec_1e4e50 velocity; velocity.x=scale*0.0f; velocity.y=scale*1000.0f; velocity.z=scale*200.0f;
 Vec_1e4e50 position; position.x=x; position.y=y; position.z=z;
 Matrix rotation;
 rotation.FUN_0022b980();
 ((owners::Mat_22ba70 *)&rotation)->FUN_0022ba70((*(Random_1e4e50**)&DAT_004e5acc)->FUN_000787e0(0.0f,6.283185482025146484375f));
 ((owners::M_22c3b0 *)&rotation)->FUN_0022c3b0((float *)(Vec_1e4e50 *)(&velocity), (float *)(Vec_1e4e50 *)(&velocity));
 rotation.FUN_0022b980();
 ((owners::Mat_22ba70 *)&rotation)->FUN_0022ba70(6.283185482025146484375f/count);
 for(int i=count;i>0;--i) {
 FUN_001e4c40(resource,&position,type,0,&velocity,1);
 ((owners::M_22c3b0 *)&rotation)->FUN_0022c3b0((float *)(Vec_1e4e50 *)(&velocity), (float *)(Vec_1e4e50 *)(&velocity));
 }
}
