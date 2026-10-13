class Obj {
  public:
    char Set(int value);
    char pad[12];
    int mField;
};

char Obj::Set(int value) {
    mField = value;
    return 1;
}
