struct State { char pad[0x9a8]; char flag; };
struct Glob { char pad[0x2218]; State* state; int mode; };
extern Glob* GetGlobal();
struct A { void F(); void G(int); };
struct B { void F(int); };
extern void Ffc300();
class Obj { public: char pad0[0x10]; int state; char pad1[0x20]; A* a; B* b; void Run(); };
void Obj::Run() {
    if (state == 0x14) {
        Glob* g = GetGlobal();
        if (!g->state || !g->state->flag) {
            state = 9;
            g = GetGlobal();
            if (g->mode == 1) {
                a->F();
                b->F(9);
                a->G(0);
                Ffc300();
            }
        }
    }
}