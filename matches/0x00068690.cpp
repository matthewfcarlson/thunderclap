class Obj_68690 {
  public:
    char pad[0x68];
    int value;
    char Set(int x);
};

char Obj_68690::Set(int x) {
    value = x;
    return 1;
}
