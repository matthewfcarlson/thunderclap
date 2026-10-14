struct E_27a570 {
    void f();
};
struct X_27a570 {
    char pad[0xa0];
    void run();
};
void X_27a570::run() {
    E_27a570* p = (E_27a570*)((char*)this + 0xa0);
    int i = 0x14;
    do {
        p = (E_27a570*)((char*)p - 8);
        p->f();
        --i;
    } while (i != 0);
}