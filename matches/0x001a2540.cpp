class Target {
  public:
    char pad[0x94];
    int m94;
    bool Set(int value);
};

bool Target::Set(int value) {
    m94 = value;
    return true;
}
