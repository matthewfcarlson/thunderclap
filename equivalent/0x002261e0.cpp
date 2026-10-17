// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002261e0 @ 0x002261e0
#include "decls/data/engine/choreo2.h"

struct Vec3 { float x,y,z; };  void __cdecl FUN_00224d70(void*,Vec3*); struct Object { char pad[0x12e4]; void* field; void FUN_002261e0(Vec3* output); }; void Object::FUN_002261e0(Vec3* output) { Vec3 value; value.x=(*(float*)&DAT_004c9e74); value.y=(*(float*)&DAT_004c9e78); value.z=(*(float*)&DAT_004c9e7c); FUN_00224d70(field,&value); *output=value; }