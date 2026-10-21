// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024a370 @ 0x0024a370
struct Object { char padding[24]; };
extern "C" void* __cdecl FUN_00249f80(void*);
extern "C" void* __cdecl FUN_0024a370(Object* object) {
    return FUN_00249f80(&object->padding[24]);
}
