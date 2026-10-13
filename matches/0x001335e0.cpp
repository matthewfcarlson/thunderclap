class Obj {
  public:
    char Pad[0x34];
    int m34;
    char Set(int value);
};

char Obj::Set(int value) {
    m34 = value;
    return 1;
}