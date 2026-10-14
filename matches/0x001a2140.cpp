class Target_1a2140 {
  public:
    char pad[0x18];
    int mValue;
    bool Set(int v);
};
bool Target_1a2140::Set(int v) {
    mValue = v;
    return true;
}
