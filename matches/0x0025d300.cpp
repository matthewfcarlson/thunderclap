extern char* g1;
extern char g2[];
void __cdecl f257f00(void*, void*);
void __cdecl f240c60(void*);
struct At { char pad[0x1c]; void f(); };
struct Obj { char pad[0x10]; void* p; char pad2[8]; };
void __cdecl f247550(void*, void*);
void __cdecl target(Obj* p) {
    f257f00(g1 + 0x14, p);
    if (p->p) f240c60(p->p);
    ((At*)((char*)p + 0x1c))->f();
    f247550(g2, p);
}
