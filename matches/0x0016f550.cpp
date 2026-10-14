class Obj_16f550 {
  public:
    char pad[0x4c];
    int m4c;
    char Set(int x);
};

char Obj_16f550::Set(int x) {
    m4c = x;
    return 1;
}
