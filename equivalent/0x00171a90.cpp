// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 14/14)
// hulkfight::motion::FootPivotAction::vfunc_3 @ 0x00171a90
struct Rig { char pad[12]; unsigned count; unsigned FUN_002843a0(unsigned,unsigned); };
struct Label { void FUN_0027b040(const char*); };
struct Anim { virtual void vfunc_0(); int unused; Label label; int pad; int field10; int field14; Anim* FUN_002248a0(); };
struct Actor { char pad[0x64]; Rig* rig; void FUN_00222890(Anim*,float,float,float,float,float,float); };
struct Handle { int FUN_00059a30(); Actor* FUN_00059a40(); };
struct Owner { Handle* FUN_000592a0(); };
struct Settings { char pad[0x18]; unsigned key1,key2; char pad2[0x18]; float a,b,c; };
extern void* __cdecl FUN_00263ea0(unsigned);
namespace hulkfight { namespace motion {
struct FootPivotAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); char pad[0x18]; Settings* settings; Owner* owner; unsigned index; Anim* anim; };
bool FootPivotAction::vfunc_3(int,int) {
 Handle* h=owner->FUN_000592a0();
 if (!h || !h->FUN_00059a30()) return false;
 Actor* actor=h->FUN_00059a40();
 if (!actor) return false;
 Rig* rig=actor->rig;
 unsigned k1=settings->key1,k2=settings->key2;
 if(k1|k2) { index=rig->FUN_002843a0(k1,k2); if(index==0xffff) index=0; }
 if(index>=rig->count) return false;
 Anim* a=(Anim*)FUN_00263ea0(0x70);
 if(a) a=a->FUN_002248a0();
 anim=a;
 a->label.FUN_0027b040("footPivot");
 anim->vfunc_0();
 anim->field10=0;
 anim->field14=2;
 actor->FUN_00222890(anim,-1.0f,settings->a,1.0f,settings->b,settings->c,-1.0f);
 return true;
}
}}
