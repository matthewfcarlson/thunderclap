// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0018cab0..0x0018ecb0 (kind game, layer game, confidence high), dominant class hulkfight::motion::TimerCondition
#include "tree_prelude.h"


// 0x0018e590 FUN_0018e590 (231 B): equivalent/0x0018e590.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?FUN_0018e590@fn_f0930188@@YAXXZ
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_f0930188 {} using namespace fn_f0930188;
namespace fn_f0930188 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_0018e590 @ 0x0018e590


} // namespace fn_f0930188
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f0930188 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl GetVariable_0018cb50();
void __cdecl SetCompare_0018cb60();
void __cdecl SetValue_0018cb70();
void __cdecl FUN_002347b0(void*,void**,int);
namespace hulkfight { namespace motion { class VarCompareCondition; } }
namespace fight {
template<class T> struct ParamName {
 virtual void slot0();
 char fields[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234a90(const char*);
};
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char fields[12];
 const char* values;
 int count;
 void (__cdecl *callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char fields[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_002348e0(const char*);
};
}
void __cdecl FUN_0018e590() {
 if (DAT_004e151c == 0) {
  void* items[3];
  fight::ParamName<hulkfight::motion::VarCompareCondition>* a = (fight::ParamName<hulkfight::motion::VarCompareCondition>*)FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::motion::VarCompareCondition>));
  if(a) { a->FUN_00234a90("variable"); a = new(a) fight::ParamName<hulkfight::motion::VarCompareCondition>; a->callback = GetVariable_0018cb50; }
  items[0]=a;
  fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>* b=(fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>));
  if(b) { int count=(*(int*)&DAT_00427754); b->FUN_00234cc0("compare"); b->count=count; b = new(b) fight::ParamEnumConstList<hulkfight::motion::VarCompareCondition>; b->values="lwB"; b->callback=SetCompare_0018cb60; }
  items[1]=b;
  fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>* c=(fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>));
  if(c) { c->FUN_002348e0("value"); c = new(c) fight::ParamIntConstRange<hulkfight::motion::VarCompareCondition>; c->callback=SetValue_0018cb70; }
  items[2]=c;
  FUN_002347b0(&DAT_004e1518,items,3);
 }
 ++DAT_004e151c;
}
} // namespace fn_f0930188

