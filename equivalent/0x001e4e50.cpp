// STATUS: equivalent (tools/equiv.py level 3: 406 inputs, branch coverage 20/20)
// FUN_001e4e50 @ 0x001e4e50
struct State { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Player { char pad[0x80]; State state; };
struct Manager { Player* FUN_00086310(); };
struct Game { char pad[0x54]; Manager* manager; };
extern Game* DAT_004dd700;
struct Random { float FUN_000787e0(float,float); };
extern Random* DAT_004e5acc;
struct Vec { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022b980(); void FUN_0022ba70(float); void FUN_0022c3b0(Vec*,Vec*); };
extern void* __cdecl FUN_001d68e0(int);
struct Effect { void FUN_001e4c40(void*,Vec*,int,int,Vec*,int); void target(int,float,float,float,float,int); };
void Effect::target(int type,float x,float y,float z,float scale,int count) {
 int active=DAT_004dd700->manager->FUN_00086310()->state.FUN_00088fa0();
 int mode=DAT_004dd700->manager->FUN_00086310()->state.FUN_00088fb0();
 if(active==0 && (mode==1 || mode==10) && (type==1 || type==2 || type==3 || type==4)) return;
 void* resource=FUN_001d68e0(type);
 if(!resource) return;
 Vec velocity; velocity.x=scale*0.0f; velocity.y=scale*1000.0f; velocity.z=scale*200.0f;
 Vec position; position.x=x; position.y=y; position.z=z;
 Matrix rotation;
 rotation.FUN_0022b980();
 rotation.FUN_0022ba70(DAT_004e5acc->FUN_000787e0(0.0f,6.283185482025146484375f));
 rotation.FUN_0022c3b0(&velocity,&velocity);
 rotation.FUN_0022b980();
 rotation.FUN_0022ba70(6.283185482025146484375f/count);
 for(int i=count;i>0;--i) {
 FUN_001e4c40(resource,&position,type,0,&velocity,1);
 rotation.FUN_0022c3b0(&velocity,&velocity);
 }
}
