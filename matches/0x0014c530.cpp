class T_14c530 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};

bool T_14c530::Set(int x) {
    value = x;
    return true;
}
