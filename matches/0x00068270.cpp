class Target {
  public:
    char pad[0x50];
    int field;
    bool Set(int value);
};

bool Target::Set(int value) {
    field = value;
    return true;
}