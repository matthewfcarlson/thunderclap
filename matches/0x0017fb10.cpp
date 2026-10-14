class Target_17fb10 {
  public:
    char pad0[0x4c];
    int value;
    bool Set(int x);
};

bool Target_17fb10::Set(int x) {
    value = x;
    return true;
}
