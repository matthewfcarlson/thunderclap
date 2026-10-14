class T_12e050 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};

bool T_12e050::Set(int x) {
    value = x;
    return true;
}
