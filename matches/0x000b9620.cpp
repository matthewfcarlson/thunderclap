struct Inner {
    void A();
    void B(int);
    bool C();
};
struct Obj {
    char pad[0x54];
    Inner* p;
    void Target();
};
void Exit();
void Obj::Target() {
    if (p) {
        p->A();
        p->B(0);
        if (!p->C())
            Exit();
    }
}
