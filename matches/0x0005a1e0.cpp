class Obj {
  public:
    char Set(int value);
    char pad[0x58];
    int m58;
};

char Obj::Set(int value) {
    m58 = value;
    return 1;
}