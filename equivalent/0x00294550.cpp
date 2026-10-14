// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00294550 @ 0x00294550
struct Matrix { unsigned int data[16]; void FUN_0022c120(); };
struct Vec_294550 { float x,y,z; Vec_294550* FUN_0022d240(const Vec_294550*, const Matrix*); };
struct Parent_294550 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual Matrix* v14(); };
struct Camera { Matrix* FUN_0028faa0(); };
extern Camera** DAT_0052c2b0;
struct Object { char pad[24]; Parent_294550* parent; void FUN_00294340(float*,Vec_294550*,Vec_294550*); void target(float a,float b,float c,Vec_294550* out1,Vec_294550* out2); };
void Object::target(float a,float b,float c,Vec_294550* out1,Vec_294550* out2) {
 Vec_294550 first,second;
 FUN_00294340(&a,&first,&second);
 if(parent) { first.FUN_0022d240(&first,parent->v14()); if(parent) second.FUN_0022d240(&second,parent->v14()); }
 Matrix m = *(*DAT_0052c2b0)->FUN_0028faa0();
 m.FUN_0022c120();
 out1->FUN_0022d240(&first,&m);
 m = *(*DAT_0052c2b0)->FUN_0028faa0();
 m.FUN_0022c120();
 out2->FUN_0022d240(&second,&m);
}