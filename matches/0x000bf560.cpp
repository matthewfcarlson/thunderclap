struct A_bf560 {
    void F();
    int G();
    void H(int);
    void K();
    void L(int);
};
struct Obj_bf560 {
    char pad[0x30];
    int m30;
    A_bf560* m34;
    A_bf560* m38;
};
extern void __cdecl FFC300();
void __fastcall Target(Obj_bf560* p) {
    if (p->m38) {
        p->m34->F();
        if (!p->m38->G()) {
            if (p->m30 && p->m34 && p->m38) {
                p->m38->H(9);
                p->m34->L(0);
                FFC300();
            }
            return;
        }
        p->m38->K();
    }
}
