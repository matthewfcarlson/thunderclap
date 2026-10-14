// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_002efa90 @ 0x002efa90
struct Object; struct Source; struct Parent;
struct Service {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
};
struct Parent {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual Parent* v28(Object*); virtual void v29(Object*);
 char pad[12]; int attached; char pad2[4]; void* data;
};
struct Source {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Source* v5(Object*);
 char pad[20]; Object* owner; char pad2[4]; Service* service; char pad3[68]; unsigned char flag1; unsigned char flag2;
 void FUN_00304740(void*);
};
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(Parent*); virtual void v14(Source*);
 Object* FUN_002ef7f0(int);
};
void* __cdecl FUN_0008d690(unsigned int);
Object* __cdecl FUN_002efa90(Source* source, Parent* parent, Object* storage) {
 if (!storage) storage = (Object*)FUN_0008d690(0x88);
 if (!storage) return 0;
 Object* result = storage->FUN_002ef7f0(0);
 if (!result) return 0;
 if (parent) {
  if (parent->attached) parent = parent->v28(result);
  else parent->v29(result);
  result->v13(parent);
 }
 if (source) {
  bool cloned = false;
  if (source->owner) { source = source->v5(result); cloned = true; }
  else source->owner = result;
  result->v14(source);
  if (!cloned) {
   if (source->flag1 || source->flag2) source->service->v10();
   source->service->v8();
  }
  if (parent && source) source->FUN_00304740(parent->data);
 }
 return result;
}
