// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_00187bb0 @ 0x00187bb0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
   
void FUN_0017f600(); void FUN_0017f620(); void FUN_0017f640();
namespace hulkfight { namespace motion { class PropMissileCountCondition; } }
struct FUN_002348e0 { virtual void slot0(); char pad[12]; void (*callback)(); int tail; FUN_002348e0(const char*); };
struct FUN_00234cc0 { virtual void slot0(); char pad[12]; const char* list; int count; void (*callback)(); int tail; FUN_00234cc0(const char*); };
namespace fight {
 template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot0(); ParamIntConstRange(const char* name) : FUN_002348e0(name) {} };
 template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot0(); ParamEnumConstList(const char* name) : FUN_00234cc0(name) {} };
}
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (!DAT_004e144c) {
 void* params[3];
 typedef fight::ParamIntConstRange<hulkfight::motion::PropMissileCountCondition> I;
 typedef fight::ParamEnumConstList<hulkfight::motion::PropMissileCountCondition> E;
 void* mem=FUN_0008d690(24);
 I* a=mem ? new(mem) I("attachmentIndex") : 0;
 if(a) a->callback=FUN_0017f600;
 params[0]=a;
 mem=FUN_0008d690(32);
 E* b=0;
 if(mem) { int count=(*(int*)&DAT_00427754); b=new(mem) E("compare"); b->count=count; b->list=((char*)&DAT_0042773c); b->callback=FUN_0017f620; }
 params[1]=b;
 mem=FUN_0008d690(24);
 I* c=mem ? new(mem) I("missiles") : 0;
 if(c) c->callback=FUN_0017f640;
 params[2]=c;
 FUN_002347b0(&DAT_004e1448,params,3);
 }
 ++DAT_004e144c;
}
