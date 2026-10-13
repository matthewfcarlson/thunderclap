class Obj {
  public:
    char pad[0x10];
    int mValue;
    char Set(int value);
};

char Obj::Set(int value) {
    mValue = value;
    return 1;
}
