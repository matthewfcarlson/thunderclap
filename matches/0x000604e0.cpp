class Obj_604e0 {
  public:
    char Pad[0x10];
    int Value;
    char Set(int a);
};

char Obj_604e0::Set(int a) {
    Value = a;
    return 1;
}
