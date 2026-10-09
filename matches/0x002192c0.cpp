struct Inner { int a; int b; int count; };
struct Obj { char pad[0x10]; Inner* value; };
extern void __cdecl helper(Obj*, int, int, int);
void __cdecl target(Obj* p) { helper(p, p->value->a, p->value->count << 2, 0); }