class C {
    char pad[0x90];
    unsigned int m;

  public:
    bool Set(unsigned int x);
};

bool C::Set(unsigned int x) {
    m = x;
    return true;
}
