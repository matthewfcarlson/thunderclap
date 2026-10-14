struct C_1cc600 {
    void run(void*);
};
struct B_1cc600 {
    char pad[0x3c];
    C_1cc600* next;
};
struct A_1cc600 {
    char pad[0x0c];
    B_1cc600* child;
};
extern A_1cc600* g_1cc600;
void __fastcall target(void* p) {
    A_1cc600* a = g_1cc600;
    if (a && a->child && a->child->next)
        a->child->next->run(p);
}