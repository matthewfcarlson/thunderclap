class O {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int x);
};

bool O::Set(int x) {
    m1c = x;
    return true;
}