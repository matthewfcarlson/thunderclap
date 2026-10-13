// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::motion::BallAndChainSpinAction::vfunc_5 @ 0x001824f0
struct Matrix { float m[16]; void FUN_0022b980(); void FUN_0022bc20(float,float,float); void FUN_0022ba70(float); void FUN_0022ca90(Matrix*,Matrix*); };
struct Item;
struct Manager { Item* FUN_00035ef0(unsigned); void FUN_0003acf0(unsigned,Item*,int,int,int,Matrix*); };
struct Owner { Manager* FUN_00059a30(); };
struct Source { Owner* FUN_000592a0(); };
struct Config { char pad[0x14]; unsigned id; float height; float offset; char pad2[4]; float speed; float x,y,z; };
namespace hulkfight { namespace motion { struct BallAndChainSpinAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,float); char pad[0x18]; Config* config; Source* source; float angle; }; bool BallAndChainSpinAction::vfunc_5(int state,float dt) { if(state==1) { if(!source) return false; angle=angle+dt*config->speed; Owner* owner=source->FUN_000592a0(); Manager* manager=owner->FUN_00059a30(); unsigned id=config->id; Item* item=manager->FUN_00035ef0(id); if(item) { Matrix translation; translation.FUN_0022b980(); translation.FUN_0022bc20(config->x,config->y,config->z); translation.m[13]=config->offset; translation.m[14]=-config->height; Matrix rotation; rotation.FUN_0022b980(); rotation.FUN_0022ba70(angle); Matrix result; result.FUN_0022b980(); result.FUN_0022ca90(&translation,&rotation); manager->FUN_0003acf0(id,item,0,0,0,&result); } } return true; } } }
