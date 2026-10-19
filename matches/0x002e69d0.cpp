struct Object;
typedef void*(__cdecl* Callback)(Object*, void*);
struct Object {
    char pad[0x44];
    Callback callback;
};
void* FUN_002e6950();
void* __cdecl FUN_002e69d0(Object* object, void* argument) {
    if (object->callback)
        return object->callback(object, argument);
    void* volatile* p = &argument;
    *p;
    return FUN_002e6950();
}