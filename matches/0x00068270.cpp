class Target_68270 {
  public:
    char pad[0x50];
    int field;
    bool Set(int value);
};

bool Target_68270::Set(int value) {
    field = value;
    return true;
}