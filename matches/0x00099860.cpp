struct Sub {
    void Fn();
};
struct Obj {
    char pad[0xc4];
    Sub* sub;
    void Target();
};
void Obj::Target() {
    ((char*)sub + 0x170);
    ((Sub*)((char*)sub + 0x170))->Fn();
}
