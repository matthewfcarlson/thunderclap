struct Sub {
    void Set(unsigned int v);
};
struct Helper {
    unsigned int Get(int x);
};
struct Owner {
    char pad[0x128];
    Sub sub;
    void Run(int x);
};
void Owner::Run(int x) {
    sub.Set(((Helper*)x)->Get(x));
}
