struct Inner_b9620 {
    void A();
    void B(int);
    bool C();
};
struct Obj_b9620 {
    char pad[0x54];
    Inner_b9620* p;
    void Target();
};
void Exit();
void Obj_b9620::Target() {
    if (p) {
        p->A();
        p->B(0);
        if (!p->C())
            Exit();
    }
}
