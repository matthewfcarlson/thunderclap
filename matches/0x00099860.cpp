struct Sub_99860 {
    void Fn(int, int);
};
struct Obj_99860 {
    char pad[0xc4];
    Sub_99860* sub;
    void Target(int, int);
};
void Obj_99860::Target(int a0, int a1) {
    ((char*)sub + 0x170);
    ((Sub_99860*)((char*)sub + 0x170))->Fn(a0, a1);
}
