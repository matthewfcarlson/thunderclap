class Obj {
  public:
    char Set(int value);
    char pad[0xc];
    int mValue;
};

char Obj::Set(int value) {
    mValue = value;
    return 1;
}
