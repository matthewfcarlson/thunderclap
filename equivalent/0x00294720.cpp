// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00294720 @ 0x00294720
struct Matrix;
struct Vec_294720 { float x,y,z; void FUN_0022d210(Matrix*); };
struct Context { Matrix* FUN_0028faa0(); };
extern Context** DAT_0052c2b0;
struct Camera { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual Matrix* v13(); };
struct Object { char pad[24]; Camera* camera; void FUN_00294720(float x,float y,float z,Vec_294720* out); };
void Object::FUN_00294720(float x,float y,float z,Vec_294720* out) {
 if (!camera) return;
 Vec_294720 v; v.x=x; v.y=y; v.z=z;
 v.FUN_0022d210((*DAT_0052c2b0)->FUN_0028faa0());
 v.FUN_0022d210(camera->v13());
 if (v.z != 0.0f) { float inverse=1.0f / v.z; out->z=v.z; out->x=v.x*inverse*0.5f; out->y=v.y*inverse*0.5f; }
 else { out->x=0.0f; out->y=0.0f; out->z=1.0f; }
}