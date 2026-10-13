class Target {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};

bool Target::Set(int v) {
    value = v;
    return true;
}
