class Target_192f50 {
  public:
    char pad[0x130];
    int field;
    bool SetField(int value);
};

bool Target_192f50::SetField(int value) {
    field = value;
    return true;
}