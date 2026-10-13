class Obj {
  public:
    char pad[0x14];
    int m14;
    char Set(int value);
};

char Obj::Set(int value) {
    m14 = value;
    return 1;
}
