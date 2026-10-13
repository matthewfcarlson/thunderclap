class Obj {
  public:
    char pad[0x10];
    int value;
    char Set(int a);
};

char Obj::Set(int a) {
    value = a;
    return 1;
}
