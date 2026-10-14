// Same code shape as 0x0030ee70 (propagated; names are from that function)
struct B_30ef00 {
    void F(int);
};
struct A_30ef00 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
void A_30ef00::Target(int x) {
    Init();
    ((B_30ef00*)((char*)this + 0x68))->F(x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}