// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"


// 0x0016b7c0 FUN_0016b7c0 (245 B): equivalent/0x0016b7c0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_0016b7c0 @98464c95970c @w78de89db7d83
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
namespace fn_f75131d9 {} using namespace fn_f75131d9;
namespace fn_f75131d9 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_0016b7c0 @ 0x0016b7c0

/* size_t: tree_prelude.h */

} // namespace fn_f75131d9
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f75131d9 {

extern void* __cdecl FUN_0008d690(unsigned int);
bool SetCompare_00165710(void*, int); /* (unb5) as defined; address taken only */ char SetHealth_00165720(void*, int); /* (unb5) as defined; address taken only */ char SetConstant_00165730(void*, int); /* (unb5) as defined; address taken only */
struct ParamBase_16b7c0 { virtual void slot0(); char padding[12]; void FUN_00234cc0(const char*); void FUN_00234960(const char*); };
namespace hulkfight { namespace motion { class GrappleHealthCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList : ParamBase_16b7c0 { virtual void slot0(); const char* values; unsigned int count; void (*callback)(); unsigned int tail; };
template<class T> struct ParamFloatConstRange : ParamBase_16b7c0 { virtual void slot0(); void (*callback)(); unsigned int tail; };
}
extern void __cdecl FUN_002347b0(unsigned int*, ParamBase_16b7c0**, unsigned int);
extern "C" void __cdecl FUN_0016b7c0() {
 if (!DAT_004e125c) {
  ParamBase_16b7c0* params[3];
  void* mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>));
  if(mem) {
   unsigned int count = (*(unsigned int*)&DAT_00427754);
   ((ParamBase_16b7c0*)mem)->FUN_00234cc0("compare");
   fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>* p = new(mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>;
   p->count=count; p->values=((char*)&DAT_0042773c); p->callback=(void (*)())SetCompare_00165710; params[0]=p;
  } else params[0]=0;
  mem=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>));
  if(mem) {
   ((ParamBase_16b7c0*)mem)->FUN_00234960("health");
   fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>* p = new(mem) fight::ParamFloatConstRange<hulkfight::motion::GrappleHealthCondition>;
   p->callback=(void (*)())SetHealth_00165720; params[1]=p;
  } else params[1]=0;
  mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>));
  if(mem) {
   ((ParamBase_16b7c0*)mem)->FUN_00234cc0("constant");
   fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>* p = new(mem) fight::ParamEnumConstList<hulkfight::motion::GrappleHealthCondition>;
   p->values=DAT_004b4d88; p->count=4; p->callback=(void (*)())SetConstant_00165730; params[2]=p;
  } else params[2]=0;
  FUN_002347b0(&DAT_004e1258,params,3);
 }
 ++DAT_004e125c;
}
} // namespace fn_f75131d9

