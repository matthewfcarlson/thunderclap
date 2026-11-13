// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012b190..0x0012d920 (kind game, layer game, confidence high), dominant class hulkfight::ai::ThreatDistanceCondition
#include "tree_prelude.h"


// 0x0012cfe0 FUN_0012cfe0 (256 B): equivalent/0x0012cfe0.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?FUN_0012cfe0@fn_fb57e000@@YAXXZ @230c903e733b @w5a84b2501913
#include "gen/owners.h"
#include "decls/data/game/hulkfight/ai.h"
namespace fn_fb57e000 {} using namespace fn_fb57e000;
namespace fn_fb57e000 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 10/10)
// FUN_0012cfe0 @ 0x0012cfe0


} // namespace fn_fb57e000
inline void* operator new(size_t, void* p) { return p; }
namespace fn_fb57e000 {

void* __cdecl FUN_0008d690(unsigned);
bool SetAngle_0012b200(void*, void*, float); /* (unb5) as defined; address taken only */
bool SetArc_0012b220(void*, float); /* (unb5) as defined; address taken only */
void* GetThreatName_0012b240(void*); /* (unb5) as defined; address taken only */
char SetThreatRespondOnlyOnce_0012b250(void*, char); /* (unb5) as defined; address taken only */
void __cdecl FUN_002347b0(void*, void*, int);
namespace hulkfight { namespace ai { class ThreatAngleCondition; } }
namespace fight {
struct Base_12cfe0 {
 virtual void dummy();
 char pad[12];
 void (__cdecl *callback)();
 unsigned tail;
 void FUN_00234960(const char*);
 void FUN_00234a90(const char*);
 void FUN_00234860(const char*);
};
template<class T> struct ParamFloatConstRange: Base_12cfe0 { virtual void dummy(); };
template<class T> struct ParamName: Base_12cfe0 { virtual void dummy(); };
template<class T> struct ParamBool: Base_12cfe0 { virtual void dummy(); };
}
void FUN_0012cfe0() {
 if (DAT_004e0e28 == 0) {
  fight::Base_12cfe0* params[4];
  void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>));
  if (p) { fight::Base_12cfe0* b=(fight::Base_12cfe0*)p; b->FUN_00234960("angle"); params[0]=new(p) fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>; params[0]->callback=(void (*)())SetAngle_0012b200; } else params[0]=0;
  p=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>));
  if(p) { fight::Base_12cfe0* b=(fight::Base_12cfe0*)p; b->FUN_00234960("arc"); params[1]=new(p) fight::ParamFloatConstRange<hulkfight::ai::ThreatAngleCondition>; params[1]->callback=(void (*)())SetArc_0012b220; } else params[1]=0;
  p=FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::ai::ThreatAngleCondition>));
  if(p) { fight::Base_12cfe0* b=(fight::Base_12cfe0*)p; b->FUN_00234a90("threatName"); params[2]=new(p) fight::ParamName<hulkfight::ai::ThreatAngleCondition>; params[2]->callback=(void (*)())GetThreatName_0012b240; } else params[2]=0;
  p=FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::ai::ThreatAngleCondition>));
  if(p) { fight::Base_12cfe0* b=(fight::Base_12cfe0*)p; b->FUN_00234860("threatRespondOnlyOnce"); params[3]=new(p) fight::ParamBool<hulkfight::ai::ThreatAngleCondition>; params[3]->callback=(void (*)())SetThreatRespondOnlyOnce_0012b250; } else params[3]=0;
  FUN_002347b0(&DAT_004e0e24,params,4);
 }
 ++DAT_004e0e28;
}
} // namespace fn_fb57e000

