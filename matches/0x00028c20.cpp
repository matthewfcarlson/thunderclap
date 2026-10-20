extern float DAT_003f335c;
extern __int64 __cdecl FUN_002672f0(void*, int, int);
struct Value {
    float* FUN_00036d00();
};
struct Object {
    char pad[0x334];
    Value* value;
};
struct Thing {
    Object* FUN_00024280(unsigned int low, unsigned int high);
    float* FUN_00028c20(void* arg);
};
float* Thing::FUN_00028c20(void* arg) {
    unsigned __int64 result = FUN_002672f0(arg, 0, 0);
    Object* object = FUN_00024280((unsigned int)result, (unsigned int)(result >> 32));
    Value* v = object ? object->value : 0;
    if (!v)
        return &DAT_003f335c;
    return v->FUN_00036d00();
}