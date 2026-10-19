// STATUS: equivalent (tools/equiv.py level 3: 19678 inputs, branch coverage 4/4)
// hulkfight::motion::BallAndChainReturnAction::vfunc_3 @ 0x00182660
struct Vec_182660 { float x,y,z; Vec_182660* FUN_0022c2b0(Vec_182660*, Vec_182660*); float FUN_0022d110(); };
struct Transform_182660 { Vec_182660* FUN_00221c40(); };
struct TransformHolder { char pad[16]; Transform_182660 transform; };
struct Item_182660 { Vec_182660* FUN_001d6b40(); };
struct Lookup_182660 { Item_182660* FUN_00035ef0(unsigned); };
struct Actor_182660 { Lookup_182660* FUN_00059a30(); TransformHolder* FUN_00059a40(); };
struct Source_182660 { Actor_182660* FUN_000592a0(); };
struct Settings_182660 { char pad[20]; unsigned key; unsigned value; char pad2[16]; Vec_182660 position; };
namespace hulkfight { namespace motion {
struct BallAndChainReturnAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
char pad[24]; Settings_182660* settings; Source_182660* source; Vec_182660 origin; Vec_182660 direction; unsigned value; float length;
};
bool BallAndChainReturnAction::vfunc_3(unsigned,unsigned) {
 if (!source) return false;
 Actor_182660* actor=source->FUN_000592a0();
 Lookup_182660* lookup=actor->FUN_00059a30();
 Item_182660* item=lookup->FUN_00035ef0(settings->key);
 if (!item) return false;
 origin=*item->FUN_001d6b40();
 Vec_182660 position=settings->position;
 Vec_182660 result;
 TransformHolder* holder=actor->FUN_00059a40();
 holder->transform.FUN_00221c40()->FUN_0022c2b0(&position, &result);
 direction=result;
 direction.x-=origin.x; direction.y-=origin.y; direction.z-=origin.z;
 length=direction.FUN_0022d110();
 value=settings->value;
 return true;
}
}}
