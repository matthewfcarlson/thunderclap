class Obj {
  public:
    char Set(int value);
    char pad[0x10];
    int m10;
};

char Obj::Set(int value) {
    m10 = value;
    return 1;
}
