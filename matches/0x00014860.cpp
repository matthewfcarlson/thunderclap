class B; class C;
class A { public: B* f(); };
class B { public: C* f(); };
class C { public: bool f(void*); };
class Obj { public: char pad[0x1c]; A* a; char pad2[4]; void* b; };
bool __fastcall target(Obj* self) {
    B* x = self->a->f();
    C* y = x->f();
    if (!y) return true;
    return y->f(self->b);
}