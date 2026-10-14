class Obj {
  public:
    char Set(int a);
    char pad[0x5c];
    int value;
};

char Obj::Set(int a) {
    value = a;
    return 1;
}
