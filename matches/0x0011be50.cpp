class Obj {
  public:
    char Set(int value);
    char pad[0x1c];
    int mValue;
};

char Obj::Set(int value) {
    mValue = value;
    return 1;
}
