class Target {
  public:
    char pad[12];
    int field;
    bool Set(int x);
};

bool Target::Set(int x) {
    field = x;
    return true;
}