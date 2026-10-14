class T_61c40 {
  public:
    char pad[0xb0];
    int value;
    bool Set(int v);
};

bool T_61c40::Set(int v) {
    value = v;
    return true;
}
