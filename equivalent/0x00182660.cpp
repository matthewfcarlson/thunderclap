// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::BallAndChainReturnAction::vfunc_3 @ 0x00182660
struct Vec { float x,y,z; Vec* FUN_0022c2b0(); float FUN_0022d110(); };
struct Transform { Vec* FUN_00221c40(Vec*, Vec*); };
struct TransformHolder { char pad[16]; Transform transform; };
struct Item { Vec* FUN_001d6b40(); };
struct Lookup { Item* FUN_00035ef0(unsigned); };
struct Actor { Lookup* FUN_00059a30(); TransformHolder* FUN_00059a40(); };
struct Source { Actor* FUN_000592a0(); };
struct Settings { char pad[20]; unsigned key; unsigned value; char pad2[16]; Vec position; };
namespace hulkfight { namespace motion {
struct BallAndChainReturnAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
char pad[24]; Settings* settings; Source* source; Vec origin; Vec direction; unsigned value; float length;
};
bool BallAndChainReturnAction::vfunc_3(unsigned,unsigned) {
 if (!source) return false;
 Actor* actor=source->FUN_000592a0();
 Lookup* lookup=actor->FUN_00059a30();
 Item* item=lookup->FUN_00035ef0(settings->key);
 if (!item) return false;
 origin=*item->FUN_001d6b40();
 Vec position=settings->position;
 Vec result;
 TransformHolder* holder=actor->FUN_00059a40();
 holder->transform.FUN_00221c40(&position,&result)->FUN_0022c2b0();
 direction=result;
 direction.x-=origin.x; direction.y-=origin.y; direction.z-=origin.z;
 length=direction.FUN_0022d110();
 value=settings->value;
 return true;
}
}}
