// STATUS: equivalent (tools/equiv.py level 3: 1172 inputs, branch coverage 18/18)
// FUN_002a6500 @ 0x002a6500
struct Parameter {
 virtual void v0(); virtual void v1(); virtual unsigned int type();
 unsigned int pad4; unsigned int name;
 void FUN_0028a1c0(float time, float* value);
};
struct List {
 char pad[20]; int count;
 Parameter* FUN_00288950(int index);
};
struct Container { List* FUN_00288a10(int index); };
struct Source {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual float time();
 virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual Container* container();
};
struct Values { float speed, p, c, a, u; };
extern int __cdecl FUN_002a5fd0(float, unsigned int, unsigned int, unsigned int, Values*);
int __cdecl FUN_002a6500(Source* source, unsigned int arg2, unsigned int arg3, unsigned int arg4) {
 Values values; values.speed=0.08f; values.p=0.5f; values.c=0.5f; values.a=0.0f; values.u=0.125f;
 float t=source->time(); float updatedTime=t;
 List* list=source->container()->FUN_00288a10(0);
 for(int i=0;i<list->count;++i) {
 Parameter* param=list->FUN_00288950(i);
 if(param->type()==0x31544c46) {
 float* value=0;
 switch(param->name) {
 case 0x4450534e: value=&values.speed; break;
 case 0x4d41504e: value=&values.p; break;
 case 0x4d41434e: value=&values.c; break;
 case 0x4d41414e: value=&values.a; break;
 case 0x4d41554e: value=&values.u; break;
 case 0x454d4954: value=&updatedTime; break;
 }
 if(value) param->FUN_0028a1c0(t,value);
 }
 }
 return FUN_002a5fd0(updatedTime,arg2,arg3,arg4,&values);
}