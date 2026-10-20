// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_0013c530 @ 0x0013c530
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
  
void FUN_001399f0(); void FUN_00139a10(); void FUN_00139a20();
struct FUN_00234a90 { virtual void slot(); char pad[12]; void (*callback)(); int tail; FUN_00234a90(const char* = "animation"); };
struct FUN_00234cc0 { virtual void slot(); char pad[12]; const char* names; int count; void (*callback)(); int tail; FUN_00234cc0(const char* = "compare"); };
struct FUN_00234960 { virtual void slot(); char pad[12]; void (*callback)(); int tail; FUN_00234960(const char* = "frame"); };
namespace hulkfight { namespace motion { class FrameCondition; } }
namespace fight {
template<class T> struct ParamName : FUN_00234a90 { virtual void slot(); };
template<class T> struct ParamEnumConstList : FUN_00234cc0 { virtual void slot(); };
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
}
void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_0013c530() {
 if (!DAT_004e0f14) {
 void* items[3];
 void* p=FUN_0008d690(24);
 if(p) { fight::ParamName<hulkfight::motion::FrameCondition>* b=new(p) fight::ParamName<hulkfight::motion::FrameCondition>; b->callback=FUN_001399f0; items[0]=b; } else items[0]=0;
 p=FUN_0008d690(32);
 if(p) { int n=(*(int*)&DAT_00427754); fight::ParamEnumConstList<hulkfight::motion::FrameCondition>* b=new(p) fight::ParamEnumConstList<hulkfight::motion::FrameCondition>; b->count=n; b->names="lwB"; b->callback=FUN_00139a10; items[1]=b; } else items[1]=0;
 p=FUN_0008d690(24);
 if(p) { fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>* b=new(p) fight::ParamFloatConstRange<hulkfight::motion::FrameCondition>; b->callback=FUN_00139a20; items[2]=b; } else items[2]=0;
 FUN_002347b0(&DAT_004e0f10,items,3);
 }
 ++DAT_004e0f14;
}