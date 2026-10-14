class Obj {
  public:
    char pad[12];
    char mValue;
    char Set(char x);
};

char Obj::Set(char x) {
    mValue = x;
    return 1;
}
