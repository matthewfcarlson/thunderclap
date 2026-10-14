class T_17fc40 {
  public:
    char pad[0x10];
    int value;
    bool Set(int x);
};
bool T_17fc40::Set(int x) {
    value = x;
    return true;
}
