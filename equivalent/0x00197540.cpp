// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::motion::FireBeamAction::vfunc_4 @ 0x00197540
struct Ref_197540 { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Beam_197540 { char pad[0x12c]; unsigned int value; };
struct Lookup_197540 { Beam_197540* FUN_00024280(unsigned int, unsigned int); };
struct Receiver_197540 { void FUN_0003ffa0(unsigned int, int); };
struct Intermediate_197540 { Receiver_197540* FUN_00059a30(); };
struct Source_197540 { Intermediate_197540* FUN_000592a0(); };
struct Effects_197540 { void FUN_0027ffb0(unsigned int); };
Effects_197540* __cdecl FUN_0027f250();
struct Manager_197540 { void FUN_001e5720(Ref_197540*); };
struct World { char pad0[0xc]; Manager_197540* manager; char pad1[0x10]; Lookup_197540* lookup; };
extern World* DAT_004dd700;
struct Resources_197540 { char pad[8]; unsigned int first; unsigned int second; };
namespace hulkfight { namespace motion {
struct FireBeamAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 char pad0[0x1c]; Source_197540* source;
 char pad1[0x28]; unsigned int fallback; Beam_197540* beam; char pad2[4]; unsigned int key1; unsigned int key2; char pad3[4]; Ref_197540* ref; Resources_197540* resources;
};
void FireBeamAction::vfunc_4() {
 if (!source) return;
 Receiver_197540* receiver = source->FUN_000592a0()->FUN_00059a30();
 if (!receiver) return;
 Lookup_197540* lookup = DAT_004dd700->lookup;
 beam = 0;
 if (lookup) beam = lookup->FUN_00024280(key1,key2);
 receiver->FUN_0003ffa0(beam ? beam->value : fallback,0);
 Effects_197540* effects = FUN_0027f250();
 if (effects) {
 if (resources && resources->first) effects->FUN_0027ffb0(resources->first);
 if (resources && resources->second) effects->FUN_0027ffb0(resources->second);
 }
 DAT_004dd700->manager->FUN_001e5720(ref);
 if (ref) { ref->vfunc_1(); ref = 0; }
}
}}
