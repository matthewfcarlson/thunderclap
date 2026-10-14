struct State_b9770 {
    char pad[0x9a8];
    char flag;
};
struct Glob_b9770 {
    char pad[0x2218];
    State_b9770* state;
    int mode;
};
extern Glob_b9770* GetGlobal();
struct A_b9770 {
    void F();
    void G(int);
};
struct B_b9770 {
    void F(int);
};
extern void Ffc300();
class Obj_b9770 {
  public:
    char pad0[0x10];
    int state;
    char pad1[0x20];
    A_b9770* a;
    B_b9770* b;
    void Run();
};
void Obj_b9770::Run() {
    if (state == 0x14) {
        Glob_b9770* g = GetGlobal();
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