// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c5900 @ 0x000c5900
#include "gen/owners.h"
struct Vec_c5900 {
 float x,y,z;
};
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual const Vec_c5900* v14();
};
void __cdecl FUN_000c5900(Object* object, int axis, float amount) {
 Vec_c5900 delta;
 delta.x=0.0f; delta.y=0.0f; delta.z=0.0f;
 float y=axis==1?amount:0.0f;
 float z=axis==2?amount:0.0f;
 float x=axis==0?amount:0.0f;
 const Vec_c5900* base=object->v14();
 delta.x=x+delta.x;
 delta.y=y+delta.y;
 delta.z=z+delta.z;
 ((owners::Obj_22d210 *)&delta)->FUN_0022d210((owners::Obj_22d210 *)(const Vec_c5900 *)base);
 ((owners::C_293af0 *)object)->FUN_00293af0((int *)(const Vec_c5900 *)(&delta));
}
