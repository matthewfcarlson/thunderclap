class Obj_682f0 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};

char Obj_682f0::Set(int x) {
    value = x;
    return 1;
}