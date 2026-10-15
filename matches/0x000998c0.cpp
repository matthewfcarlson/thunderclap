class Target {
  public:
    char pad[0xc4];
    struct Inner {
        char p[0x220];
        int a;
        int b;
    }* m;
    void Set(int a, int b);
};

void Target::Set(int a, int b) {
    m->a = a;
    m->b = b;
}
