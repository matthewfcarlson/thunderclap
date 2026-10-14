class Obj {
  public:
    char Pad[0x18];
    int value;
    char Set(int x);
};

char Obj::Set(int x) {
    value = x;
    return 1;
}
