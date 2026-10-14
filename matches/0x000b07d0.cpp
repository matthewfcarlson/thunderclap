class Target_b07d0 {
    char pad[0x498];
    int value;

  public:
    bool Set(int x);
};
bool Target_b07d0::Set(int x) {
    value = x;
    return true;
}