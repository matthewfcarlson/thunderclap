struct Sub {
    void Fn();
};
struct Obj {
    char pad[0xc4];
    Sub* m;
    void Fn();
};
void Obj::Fn() {
    Sub* p = m;
    p = (Sub*)((char*)p + 0x218);
    p->Fn();
}
