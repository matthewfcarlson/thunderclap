class Obj {
  public:
    char pad[12];
    char mValue;
    char Set(unsigned char x);
};

char Obj::Set(unsigned char x) {
    mValue = x;
    return 1;
}
