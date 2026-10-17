// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CLocator::vfunc_10 @ 0x001fba70
#include "decls/data/game/global.h"

struct Vec3 { float x,y,z; };  void __cdecl FUN_00224d70(void*, Vec3*); struct CLocator { char pad[0x1c]; void* field; void vfunc_10(Vec3* out); }; void CLocator::vfunc_10(Vec3* out) { Vec3 v; v.x=(*(float*)&DAT_004c85c8); v.y=(*(float*)&DAT_004c85cc); v.z=(*(float*)&DAT_004c85d0); FUN_00224d70(field,&v); *out=v; }