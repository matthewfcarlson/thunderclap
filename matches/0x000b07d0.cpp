class Target {
    char pad[0x498];
    int value;

  public:
    bool Set(int x);
};
bool Target::Set(int x) {
    value = x;
    return true;
}