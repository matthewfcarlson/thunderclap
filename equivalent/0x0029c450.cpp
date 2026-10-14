// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_0029c450 @ 0x0029c450
struct TypeInfo;
extern TypeInfo DAT_004cf680, DAT_004c534c, DAT_004cf658, DAT_004c532c, DAT_004c5368, DAT_004cf634;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
struct Object {
 char padding[0x2c];
 void* first;
 void* second;
 void* third;
 void* fourth;
 void* fifth;
 void* FUN_0029c450(void* value);
};
void* Object::FUN_0029c450(void* value) {
 if (!value) return 0;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004cf680,0)) return first;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004cf658,0)) return second;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004c532c,0)) return third;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004c5368,0)) return fourth;
 if (FUN_00344e74(value,0,&DAT_004c534c,&DAT_004cf634,0)) return fifth;
 return 0;
}