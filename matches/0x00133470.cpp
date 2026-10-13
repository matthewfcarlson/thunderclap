class Obj {
  public:
    char pad[0xc];
    int mValue;
    char Set(int value);
};

char Obj::Set(int value) {
    mValue = value;
    return 1;
}
