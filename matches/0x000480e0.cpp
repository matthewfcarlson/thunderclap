class Target {
  public:
    char pad[12];
    int value;
    bool Set(int x);
};

bool Target::Set(int x) {
    value = x;
    return true;
}
