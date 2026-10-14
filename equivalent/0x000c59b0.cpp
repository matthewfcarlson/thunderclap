// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c59b0 @ 0x000c59b0
struct Matrix { float m[16]; void FUN_0022bc20(float x,float y,float z); };
struct Vector { float x,y,z; void FUN_0022d260(Matrix* matrix); };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual Matrix* v14();
 void FUN_00293a90(Vector* value);
};
void __cdecl FUN_000c59b0(Object* object,int axis,float angle) {
 Vector value; value.x=0.0f; value.y=0.0f; value.z=1.0f;
 float x=0.0f,y=0.0f,z=0.0f;
 if(axis==2) z=angle; else if(axis==1) y=angle;
 if(axis==0) x=angle;
 Matrix* original=object->v14();
 Matrix rotation;
 rotation.FUN_0022bc20(x,y,z);
 value.FUN_0022d260(&rotation);
 value.FUN_0022d260(original);
 object->FUN_00293a90(&value);
}