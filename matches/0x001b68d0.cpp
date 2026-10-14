extern int g_1b68d0;
struct A_1b68d0 {
    char pad[12];
    int value;
};
void __stdcall FUN_001b68d0(A_1b68d0* p) {
    g_1b68d0 = p->value;
}