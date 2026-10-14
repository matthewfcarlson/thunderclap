// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c5900 @ 0x000c5900
struct Vec {
 float x,y,z;
 void FUN_0022d210(const Vec* other);
};
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual const Vec* v14();
 void FUN_00293af0(const Vec* value);
};
void __cdecl FUN_000c5900(Object* object, int axis, float amount) {
 Vec delta;
 delta.x=0.0f; delta.y=0.0f; delta.z=0.0f;
 float y=axis==1?amount:0.0f;
 float z=axis==2?amount:0.0f;
 float x=axis==0?amount:0.0f;
 const Vec* base=object->v14();
 delta.x=x+delta.x;
 delta.y=y+delta.y;
 delta.z=z+delta.z;
 delta.FUN_0022d210(base);
 object->FUN_00293af0(&delta);
}
