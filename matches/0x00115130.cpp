class Obj_115130 {
  public:
    char pad[0xc];
    int value;
    char Set(int x);
};

char Obj_115130::Set(int x) {
    value = x;
    return 1;
}
