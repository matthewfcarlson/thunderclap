class X {
  public:
    char pad[0x18];
    struct E {
        char c;
        char pad[0x1b];
    };
    union {
        E e[32];
        struct {
            char skip[0x368];
            int v;
        };
    };
    X();
};
X::X() {
    for (int i = 0; i < 32; i++)
        e[i].c = 0;
    v = 0;
}