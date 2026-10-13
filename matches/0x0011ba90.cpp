class Obj {
  public:
    char Pad[0x30];
    int m30;
    char Set(int x);
};

char Obj::Set(int x) {
    m30 = x;
    return 1;
}
