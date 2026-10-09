typedef unsigned char byte;
extern void __cdecl Ref(void*);
struct Obj { int a; int b; Obj* Run(byte flags); };
Obj* Obj::Run(byte flags) {
    int value = a;
    b = value;
    if (value) Ref((void*)value);
    if (flags & 1) Ref(this);
    return this;
}