class Obj {
  public:
    char pad[0x10];
    int m10;
    char Set(int value);
};

char Obj::Set(int value) {
    m10 = value;
    return 1;
}
