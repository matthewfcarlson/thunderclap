typedef unsigned char byte_306a90;
extern void __cdecl Ref(void*);
extern void __cdecl Free(void*);
struct Obj_306a90 {
    int a;
    int b;
    Obj_306a90* Run(byte_306a90 flags);
};
Obj_306a90* Obj_306a90::Run(byte_306a90 flags) {
    int value = a;
    b = value;
    if (value)
        Ref((void*)value);
    if (flags & 1)
        Free((void*)this);
    return this;
}
