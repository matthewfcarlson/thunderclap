// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 30/30)
// hulkfight::motion::PropMissileCountCondition::vfunc_6 @ 0x00181bd0
struct TypeDescriptor_181bd0 { unsigned int data; }; extern TypeDescriptor_181bd0 DAT_00494b44, DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeDescriptor_181bd0*, TypeDescriptor_181bd0*, int);
struct MissileSource { int FUN_001d6c50(); };
struct Actor_181bd0 { char pad[0x128]; MissileSource* active; MissileSource* FUN_00035ef0(int); };
struct ActorHandle { Actor_181bd0* FUN_00059a30(); };
struct Context { ActorHandle* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct PropMissileCountCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Context*, void*);
 char pad[8]; int slot; unsigned int comparison; int threshold;
};
bool PropMissileCountCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor_181bd0* actor = context->FUN_000592a0()->FUN_00059a30();
 int index = slot;
 if (!actor) return false;
 MissileSource* source;
 if (index < 0) source = actor->active;
 else { if (index >= 8) return false; source = actor->FUN_00035ef0(index); }
 if (!source) return false;
 int count = source->FUN_001d6c50();
 switch (comparison) {
 case 0: return count < threshold;
 case 1: return count <= threshold;
 case 2: return count == threshold;
 case 3: return count != threshold;
 case 4: return count >= threshold;
 case 5: return count > threshold;
 default: return false;
 }
}
}}
