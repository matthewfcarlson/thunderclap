class O {
    char pad[0x18];
    int m18;

  public:
    bool Fn(int a);
};

bool O::Fn(int a) {
    m18 = a;
    return true;
}
