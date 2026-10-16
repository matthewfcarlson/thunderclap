// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00161c10 @ 0x00161c10
#include "decls/data/game/hulkfight/motion.h"

void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void FUN_0015a830(); void FUN_0015a840(); void FUN_0015a850();
struct FUN_00234ba0 { FUN_00234ba0(const char* = "joint"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
struct FUN_00234960 { FUN_00234960(const char* = "thresholdDistance"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
struct FUN_00234860 { FUN_00234860(const char* = "planted"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
namespace hulkfight { namespace motion { class JointPlantedCondition; } }
namespace fight {
template<class T> struct ParamNameConstList : FUN_00234ba0 { virtual void slot(); };
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
template<class T> struct ParamBool : FUN_00234860 { virtual void slot(); };
}
 
void __cdecl FUN_002347b0(int*,void**,int);
void target() {
 if (!DAT_004e1164) {
 void* params[3];
 typedef fight::ParamNameConstList<hulkfight::motion::JointPlantedCondition> A;
 typedef fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition> B;
 typedef fight::ParamBool<hulkfight::motion::JointPlantedCondition> C;
 A* a=(A*)FUN_0008d690(24); if(a) { new(a) A; a->callback=FUN_0015a830; } params[0]=a;
 B* b=(B*)FUN_0008d690(24); if(b) { new(b) B; b->callback=FUN_0015a840; } params[1]=b;
 C* c=(C*)FUN_0008d690(24); if(c) { new(c) C; c->callback=FUN_0015a850; } params[2]=c;
 FUN_002347b0(&DAT_004e1160,params,3);
 }
 ++DAT_004e1164;
}