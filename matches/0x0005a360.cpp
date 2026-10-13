class Obj {
  public:
    char Pad[12];
    int mValue;
    char Set(int value);
};

char Obj::Set(int value) {
    mValue = value;
    return 1;
}
