// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002a8aa0 @ 0x002a8aa0
struct Object { virtual void AddRef(); virtual void Release(); };
extern char DAT_004c532c, DAT_004c534c, DAT_004c5368, DAT_004cf634, DAT_004cf658;
extern void* __cdecl FUN_00344e74(Object*, int, const void*, const void*, int);
struct Owner {
 char pad[0x110];
 int kind;
 Object* object;
 void Set(Object* value);
};
void Owner::Set(Object* value) {
 if (value) value->AddRef();
 if (object) object->Release();
 object = value;
 kind = -1;
 if (!object) { kind = 0; return; }
 if (FUN_00344e74(object,0,&DAT_004c534c,&DAT_004cf658,0)) { kind=2; return; }
 if (FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c532c,0)) { kind=1; return; }
 if (FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c5368,0)) { kind=3; return; }
 kind = FUN_00344e74(object,0,&DAT_004c534c,&DAT_004cf634,0) ? 4 : 0;
}