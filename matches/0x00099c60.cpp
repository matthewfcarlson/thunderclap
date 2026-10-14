struct Sub_99c60 {
    char pad[0x228];
    int value;
};
struct Obj_99c60 {
    char pad[0xc4];
    Sub_99c60* sub;
    void Set(int v);
};
void Obj_99c60::Set(int v) {
    sub->value = v;
}
