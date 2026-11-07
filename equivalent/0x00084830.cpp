// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00084830 @ 0x00084830
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
struct Vec_84830 { float x,y,z; hulk_freg FUN_0022d110();  };
struct Matrix { float m[16]; void FUN_0022b980();  void FUN_0022bec0(Vec_84830*,Vec_84830*);  };
struct Renderer_84830 { void FUN_001dd470(unsigned,Matrix*,unsigned); };
struct World { char pad[12]; Renderer_84830* renderer; }; 
struct Object { char pad[0x34]; unsigned id; char pad2[0x28]; Vec_84830 position; Vec_84830 direction; void FUN_00084830(unsigned arg); };
void Object::FUN_00084830(unsigned arg) { direction.y=0.0f; direction.FUN_0022d110(); union { float f; unsigned u; } length; length.f=direction.x*direction.x+direction.y*direction.y+direction.z*direction.z; length.u &= 0x7fffffff; if (!(length.f<=1e-05f)) { Matrix rotation; rotation.FUN_0022b980(); ((owners::Mat_22ba70 *)&rotation)->FUN_0022ba70(1.5707963705062866f); ((owners::Obj_22d260 *)&direction)->FUN_0022d260((owners::Obj_22d260 *)(&rotation)); Matrix transform; transform.FUN_0022b980(); Vec_84830 up; up.x=0.0f; up.y=1.0f; up.z=0.0f; transform.FUN_0022bec0(&direction,&up); ((owners::Target_22be40 *)&transform)->FUN_0022be40((const int *)(Vec_84830 *)(&position)); DAT_004dd700->renderer->FUN_001dd470(id,&transform,arg); } }
