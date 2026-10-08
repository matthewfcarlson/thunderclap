typedef unsigned int u32;
struct B { void F(u32, u32); };
struct A { char pad[8]; u32 a; B* b; };
void __fastcall FUN_00310070(A* self) { self->b->F(self->a, 0); }