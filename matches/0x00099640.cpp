struct Part {
    void First(int);
    void Second(int);
};
struct Obj {
    char pad[0xc4];
    struct Holder {
        char pad[0x1a8];
        Part part;
    }* holder;
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    holder->part.First(a);
    holder->part.Second(b);
}