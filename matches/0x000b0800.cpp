class Target_b0800 {
  public:
    char pad[0x4a4];
    int value;
    bool Set(int x);
};
bool Target_b0800::Set(int x) {
    value = x;
    return true;
}