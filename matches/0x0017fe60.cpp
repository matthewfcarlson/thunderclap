class Obj {
  public:
    char pad[0x10];
    int mField;
    char Set(int value);
};

char Obj::Set(int value) {
    mField = value;
    return 1;
}
