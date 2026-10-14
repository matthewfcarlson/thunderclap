struct B_30ee70 {
    void F(int);
};
struct A_30ee70 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
void A_30ee70::Target(int x) {
    Init();
    ((B_30ee70*)((char*)this + 0x68))->F(x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}