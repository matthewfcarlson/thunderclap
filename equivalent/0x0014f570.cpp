// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// hulkfight::motion::HitReactionFloatAction::vfunc_3 @ 0x0014f570
struct Local { char data[120]; unsigned value; char rest[28]; void FUN_00059820(); void FUN_00059300(); };
struct State { unsigned first; unsigned active; char pad[36]; void FUN_002322f0(unsigned,unsigned); unsigned char FUN_00231ee0(); };
struct Manager { void FUN_000437a0(unsigned,Local*,State*,unsigned,unsigned); };
struct Intermediate { Manager* FUN_00059a30(); };
struct Context { char pad[12]; unsigned field; Intermediate* FUN_000592a0(); };
// equiv-conv: FUN_0014f2f0 eax esi edi
void FUN_0014f2f0(Context*,void*,Local*);
namespace hulkfight { namespace motion {
struct HitReactionFloatAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual unsigned char vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
 char pad4[8]; unsigned flags; char pad10[12]; void* source; Context* context; State state; unsigned argument; unsigned char enabled;
};
unsigned char HitReactionFloatAction::vfunc_3(unsigned a,unsigned b) {
 argument=a;
 Manager* manager=context->FUN_000592a0()->FUN_00059a30();
 Local local;
 local.FUN_00059820();
 FUN_0014f2f0(context,source,&local);
 manager->FUN_000437a0(local.value,&local,&state,context->field,0);
 if(state.active) flags &= ~3u; else flags=(flags & ~2u)|1;
 state.FUN_002322f0(argument,b);
 enabled=1;
 unsigned char result=state.FUN_00231ee0();
 local.FUN_00059300();
 return result;
}
}}
