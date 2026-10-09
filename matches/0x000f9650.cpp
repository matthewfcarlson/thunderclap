struct Inner {
    void Call(int, int, int, int);
};
struct Obj {
    char pad[0x284];
    Inner* p;
    void Target(int a, int b, int c);
};
void Obj::Target(int a, int b, int c) {
    p->Call(a, b, c, 1);
}