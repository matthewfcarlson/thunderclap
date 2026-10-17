// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00028c20 @ 0x00028c20
extern float DAT_003f335c;
extern __int64 __cdecl FUN_002672f0(void *, int, int);
struct Object { char pad[0x334]; struct Value *value; };
struct Value { float *FUN_00036d00(); };
struct Thing { Object *FUN_00024280(unsigned int low, unsigned int high); float *FUN_00028c20(void *arg); };
float *Thing::FUN_00028c20(void *arg) {
    __int64 result = FUN_002672f0(arg, 0, 0);
    Object *object = FUN_00024280((unsigned int)result, (unsigned int)(result >> 32));
    if (!object || !object->value) return &DAT_003f335c;
    return object->value->FUN_00036d00();
}