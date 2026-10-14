class O {
  public:
    char pad[0x1c];
    int m;
    bool f(int a);
};

bool O::f(int a) {
    m = a;
    return true;
}
