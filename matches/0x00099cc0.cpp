struct Sub_99cc0 {
    char pad[0x1b8];
    int value;
};
struct Obj_99cc0 {
    char pad[0xc4];
    Sub_99cc0* sub;
    void Set(int x);
};
void Obj_99cc0::Set(int x) {
    sub->value = x;
}
