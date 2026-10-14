struct Sub {
    char pad[0x1b8];
    int value;
};
struct Obj {
    char pad[0xc4];
    Sub* sub;
    void Set(int x);
};
void Obj::Set(int x) {
    sub->value = x;
}
