struct Sub {
    char pad[0x228];
    int value;
};
struct Obj {
    char pad[0xc4];
    Sub* sub;
    void Set(int v);
};
void Obj::Set(int v) {
    sub->value = v;
}
