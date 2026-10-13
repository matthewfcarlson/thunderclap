class Obj {
  public:
    char Pad[12];
    int mField;
    char Set(int value);
};
char Obj::Set(int value) {
    mField = value;
    return 1;
}
