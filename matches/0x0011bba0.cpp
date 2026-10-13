class Target {
  public:
    char pad[0x30];
    int m30;
    bool Set(int value);
};

bool Target::Set(int value) {
    m30 = value;
    return true;
}
