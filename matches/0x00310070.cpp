typedef unsigned int u32_310070;
struct B_310070 {
    void F(u32_310070, u32_310070);
};
struct A_310070 {
    char pad[8];
    u32_310070 a;
    B_310070* b;
};
void __fastcall FUN_00310070(A_310070* self) {
    self->b->F(self->a, 0);
}