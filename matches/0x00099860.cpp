struct Sub_99860 {
    void Fn();
};
struct Obj_99860 {
    char pad[0xc4];
    Sub_99860* sub;
    void Target();
};
void Obj_99860::Target() {
    ((char*)sub + 0x170);
    ((Sub_99860*)((char*)sub + 0x170))->Fn();
}
