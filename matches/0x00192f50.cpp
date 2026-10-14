class Target {
  public:
    char pad[0x130];
    int field;
    bool SetField(int value);
};

bool Target::SetField(int value) {
    field = value;
    return true;
}