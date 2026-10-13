class Obj {
  public:
    char pad[0x68];
    int value;
    char Set(int x);
};

char Obj::Set(int x) {
    value = x;
    return 1;
}
