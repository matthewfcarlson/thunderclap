// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001899a0..0x0018b4e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00189d50 FUN_00189d50 (231 B): equivalent/0x00189d50.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00189d50 @96ca9fb3153c @w71dec0876d2b
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_f4028fad {} using namespace fn_f4028fad;
namespace fn_f4028fad {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00189d50 @ 0x00189d50

/* size_t: tree_prelude.h */

} // namespace fn_f4028fad
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f4028fad {

void* __cdecl FUN_0008d690(unsigned int);
void SetAttachmentIndex_0017f550(); void SetCompare_0017f570(); void GetState_0017f580();
namespace hulkfight { namespace motion { class PropStateByNameCondition; } }
struct IntBase_189d50 { char data[24]; void FUN_002348e0(const char*); };
struct EnumBase_189d50 { char data[32]; void FUN_00234cc0(const char*); };
struct NameBase_189d50 { char data[24]; void FUN_00234a90(const char*); };
namespace fight {
template<class T> struct ParamIntConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; int* list; int count; void (*callback)(); int tail; };
template<class T> struct ParamName { virtual void slot0(); char pad[12]; void (*callback)(); int tail; };
}
void __cdecl FUN_002347b0(int*,void**,int);
extern "C" void FUN_00189d50() {
 if (!(*(int*)&DAT_004e143c)) {
 void* p[3];
 void* a=FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>));
 if(a) { ((IntBase_189d50*)a)->FUN_002348e0("attachmentIndex"); fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>* obj=new(a) fight::ParamIntConstRange<hulkfight::motion::PropStateByNameCondition>; obj->callback=SetAttachmentIndex_0017f550; }
 p[0]=a;
 void* b=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>));
 if(b) { int n=(*(int*)&DAT_00427760); ((EnumBase_189d50*)b)->FUN_00234cc0("compare"); fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>* obj=new(b) fight::ParamEnumConstList<hulkfight::motion::PropStateByNameCondition>; obj->count=n; obj->list=((int*)&DAT_00427758); obj->callback=SetCompare_0017f570; }
 p[1]=b;
 void* c=FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::motion::PropStateByNameCondition>));
 if(c) { ((NameBase_189d50*)c)->FUN_00234a90("state"); fight::ParamName<hulkfight::motion::PropStateByNameCondition>* obj=new(c) fight::ParamName<hulkfight::motion::PropStateByNameCondition>; obj->callback=GetState_0017f580; }
 p[2]=c;
 FUN_002347b0(((int*)&DAT_004e1438),p,3);
 }
 ++(*(int*)&DAT_004e143c);
}
} // namespace fn_f4028fad

