// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 30/30)
// hulkfight::motion::CollisionSourceNameCondition::vfunc_6 @ 0x0014e6b0
typedef unsigned __int64 U64_14e6b0;
extern int DAT_00494b44;
extern int DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct NameProvider_14e6b0 { U64_14e6b0 FUN_000443c0(); };
struct NameData { char pad[8]; unsigned low, high; };
struct SourceObject { char pad0[0xec]; NameData* name; char pad1[0x2c]; NameProvider_14e6b0* provider; };
struct Source_14e6b0 { char pad[8]; SourceObject* object; unsigned type; };
struct Result_14e6b0 { char pad[0x4c]; Source_14e6b0* source; };
struct Params { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Result_14e6b0* slot3(); };
namespace hulkfight { namespace motion {
struct CollisionSourceNameCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(unsigned, Params*, unsigned);
 char pad[8]; unsigned mode; unsigned low, high;
};
bool CollisionSourceNameCondition::vfunc_6(unsigned, Params* params, unsigned) {
 if (!FUN_00344e74(params,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Result_14e6b0* result=params->slot3();
 if (!result || !result->source) return false;
 Source_14e6b0* source=result->source;
 unsigned lo=0, hi=0;
 if (source->type==1) {
  if (source->object && source->object->provider) {
   U64_14e6b0 value=source->object->provider->FUN_000443c0();
   lo=(unsigned)value; hi=(unsigned)(value>>32);
  }
 } else if (source->type==5) {
  if (source->object && source->object->name) {
   lo=source->object->name->low; hi=source->object->name->high;
  }
 }
 if (mode==0) return lo==low && hi==high;
 if (mode==1) return lo!=low || hi!=high;
 return false;
}
}}
