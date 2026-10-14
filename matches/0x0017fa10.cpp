class X_17fa10 {
  public:
    char pad[0x34];
    int value;
    bool Set(int v);
};
bool X_17fa10::Set(int v) {
    value = v;
    return true;
}
