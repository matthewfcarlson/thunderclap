class Obj {
  public:
    char Pad[0x10];
    int Value;
    char Set(int a);
};

char Obj::Set(int a) {
    Value = a;
    return 1;
}
