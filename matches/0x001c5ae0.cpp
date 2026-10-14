struct Sub_1c5ae0 {
    void Set(unsigned int v);
};
struct Helper {
    unsigned int Get(int x);
};
struct Owner_1c5ae0 {
    char pad[0x128];
    Sub_1c5ae0 sub;
    void Run(int x);
};
void Owner_1c5ae0::Run(int x) {
    sub.Set(((Helper*)x)->Get(x));
}
