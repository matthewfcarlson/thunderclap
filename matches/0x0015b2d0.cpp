class Obj {
  public:
    char m0[0xc8];
    int mValue;
    char Set(int value);
};

char Obj::Set(int value) {
    mValue = value;
    return 1;
}
