// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002e69d0 @ 0x002e69d0
struct Object;
typedef void (__cdecl *Callback)(Object *, void *);
struct Object { char pad[0x44]; Callback callback; };
// equiv-conv: FUN_002e6950 stack eax
void FUN_002e6950(Object *, void *);
void __cdecl FUN_002e69d0(Object *object, void *argument) {
    if (object->callback)
        object->callback(object, argument);
    else
        FUN_002e6950(object, argument);
}