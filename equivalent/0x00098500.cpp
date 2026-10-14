// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00098500 @ 0x00098500
extern "C" double __cdecl cos(double);
extern float __cdecl FUN_000189c0(float);
struct Vector { float x,y,z; };
extern void __cdecl FUN_000a04c0(Vector*,float*,float*,float*);
struct Data { char pad0[4]; float scale; char pad8[0x1c]; float angle; char pad28[8]; Vector pos; };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual float v8(); virtual void v9(); virtual float v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual Data* v14();
 virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
 virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
 virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
 virtual Vector* v27(Vector*);
 char padding[0xd0]; unsigned int value;
};
struct Output { Vector pos; float a,b,c,d; unsigned int value; float e,f; };
void __stdcall target(Object* obj, Output* out) {
 Vector temp;
 Vector* p=obj->v27(&temp);
 out->pos.x=p->x; out->pos.y=p->y; out->pos.z=p->z;
 Data* data=obj->v14();
 temp.x=data->pos.x-out->pos.x;
 temp.y=data->pos.y-out->pos.y;
 temp.z=data->pos.z-out->pos.z;
 FUN_000a04c0(&temp,&out->a,&out->b,&out->c);
 float angle=FUN_000189c0(data->angle);
 float ratio=(float)(data->scale/cos(angle));
 out->d=FUN_000189c0(ratio);
 out->value=obj->value;
 out->e=obj->v8();
 out->f=obj->v10();
}