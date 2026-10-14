class Obj_10c390 {
  public:
    char pad[0xd];
    char v;
    char Set(unsigned char x);
};

char Obj_10c390::Set(unsigned char x) {
    v = x;
    return 1;
}
