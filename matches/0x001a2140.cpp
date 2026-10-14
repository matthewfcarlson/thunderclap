class Target {
  public:
    char pad[0x18];
    int mValue;
    bool Set(int v);
};
bool Target::Set(int v) {
    mValue = v;
    return true;
}
