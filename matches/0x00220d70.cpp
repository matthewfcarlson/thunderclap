typedef unsigned int u32;
struct Obj { char pad[0x18]; u32 a; u32 b; char tail[4]; };
void helper(Obj*, void*, u32);
void target(Obj* p, u32 x) { p->b = p->a; helper(p, &p->tail, x); }