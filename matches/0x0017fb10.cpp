class Target {
  public:
    char pad0[0x4c];
    int value;
    bool Set(int x);
};

bool Target::Set(int x) {
    value = x;
    return true;
}
