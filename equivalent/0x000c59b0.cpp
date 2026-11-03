// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c59b0 @ 0x000c59b0
#include "gen/owners.h"
struct Matrix { float m[16];  };
struct Vector { float x,y,z;  };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual Matrix* v14();
};
void __cdecl FUN_000c59b0(Object* object,int axis,float angle) {
 Vector value; value.x=0.0f; value.y=0.0f; value.z=1.0f;
 float x=0.0f,y=0.0f,z=0.0f;
 if(axis==2) z=angle; else if(axis==1) y=angle;
 if(axis==0) x=angle;
 Matrix* original=object->v14();
 Matrix rotation;
 ((owners::Matrix_22bc20 *)&rotation)->FUN_0022bc20(x, y, z);
 ((owners::Obj_22d260 *)&value)->FUN_0022d260((owners::Obj_22d260 *)(Matrix *)(&rotation));
 ((owners::Obj_22d260 *)&value)->FUN_0022d260((owners::Obj_22d260 *)(Matrix *)original);
 ((owners::C_293a90 *)object)->FUN_00293a90((int *)(Vector *)(&value));
}