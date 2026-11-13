// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00161c10..0x00163a90 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight/motion.h"
#define TREE_TU_BEGIN namespace fn_fc15367f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc15367f {} using namespace fn_fc15367f;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fc15367f {
void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_fc15367f
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fc15367f {
void* FUN_0015a830(void*); /* (unb4) as defined; address taken only */
bool FUN_0015a840(void*, int); /* (unb4) as defined; address taken only */
char FUN_0015a850(void*, char); /* (unb4) as defined; address taken only */
struct FUN_00234ba0 { FUN_00234ba0(const char* = "joint"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
struct FUN_00234960 { FUN_00234960(const char* = "thresholdDistance"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
struct FUN_00234860 { FUN_00234860(const char* = "planted"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
namespace hulkfight { namespace motion {
class JointPlantedCondition;
} }
namespace fight {
template<class T> struct ParamNameConstList : FUN_00234ba0 { virtual void slot(); };
}
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
}
namespace fight {
template<class T> struct ParamBool : FUN_00234860 { virtual void slot(); };
}
void __cdecl FUN_002347b0(int*,void**,int);


// 0x00161c10 FUN_00161c10 (213 B): equivalent/0x00161c10.cpp
// sym: ?target@fn_fc15367f@@YAXXZ @df3eec2335b7 @wddeddd0f6bf5
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00161c10 @ 0x00161c10
void target() {
 if (!DAT_004e1164) {
 void* params[3];
 typedef fight::ParamNameConstList<hulkfight::motion::JointPlantedCondition> A;
 typedef fight::ParamFloatConstRange<hulkfight::motion::JointPlantedCondition> B;
 typedef fight::ParamBool<hulkfight::motion::JointPlantedCondition> C;
 A* a=(A*)FUN_0008d690((int)sizeof(A)); if(a) { new(a) A; a->callback=(void (*)())FUN_0015a830; } params[0]=a;
 B* b=(B*)FUN_0008d690((int)sizeof(B)); if(b) { new(b) B; b->callback=(void (*)())FUN_0015a840; } params[1]=b;
 C* c=(C*)FUN_0008d690((int)sizeof(C)); if(c) { new(c) C; c->callback=(void (*)())FUN_0015a850; } params[2]=c;
 FUN_002347b0(&DAT_004e1160,params,3);
 }
 ++DAT_004e1164;
}

} // namespace fn_fc15367f
