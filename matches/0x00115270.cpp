class Target_115270 {
  public:
    char pad[0x24];
    int mValue;
    bool Set(int x);
};

bool Target_115270::Set(int x) {
    mValue = x;
    return true;
}
