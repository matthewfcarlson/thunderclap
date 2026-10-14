class Obj_16fae0 {
  public:
    char pad[0x10];
    int m;
    char Set(int x);
};

char Obj_16fae0::Set(int x) {
    m = x;
    return 1;
}
