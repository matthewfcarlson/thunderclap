class Target {
  public:
    char pad[0x9c];
    int value;
    bool Set(int v);
};
bool Target::Set(int v) {
    value = v;
    return true;
}