// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::motion::FireBeamAction::vfunc_4 @ 0x00197540
struct Ref { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Beam { char pad[0x12c]; unsigned int value; };
struct Lookup { Beam* FUN_00024280(unsigned int, unsigned int); };
struct Receiver { void FUN_0003ffa0(unsigned int, int); };
struct Intermediate { Receiver* FUN_00059a30(); };
struct Source { Intermediate* FUN_000592a0(); };
struct Effects { void FUN_0027ffb0(unsigned int); };
Effects* __cdecl FUN_0027f250();
struct Manager { void FUN_001e5720(Ref*); };
struct World { char pad0[0xc]; Manager* manager; char pad1[0x10]; Lookup* lookup; };
extern World* DAT_004dd700;
struct Resources { char pad[8]; unsigned int first; unsigned int second; };
namespace hulkfight { namespace motion {
struct FireBeamAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 char pad0[0x1c]; Source* source;
 char pad1[0x28]; unsigned int fallback; Beam* beam; char pad2[4]; unsigned int key1; unsigned int key2; char pad3[4]; Ref* ref; Resources* resources;
};
void FireBeamAction::vfunc_4() {
 if (!source) return;
 Receiver* receiver = source->FUN_000592a0()->FUN_00059a30();
 if (!receiver) return;
 Lookup* lookup = DAT_004dd700->lookup;
 beam = 0;
 if (lookup) beam = lookup->FUN_00024280(key1,key2);
 receiver->FUN_0003ffa0(beam ? beam->value : fallback,0);
 Effects* effects = FUN_0027f250();
 if (effects) {
 if (resources && resources->first) effects->FUN_0027ffb0(resources->first);
 if (resources && resources->second) effects->FUN_0027ffb0(resources->second);
 }
 DAT_004dd700->manager->FUN_001e5720(ref);
 if (ref) { ref->vfunc_1(); ref = 0; }
}
}}
