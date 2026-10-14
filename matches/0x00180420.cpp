class Obj_180420 {
  public:
    char pad[0x14];
    int value;
    char Set(int x);
};

char Obj_180420::Set(int x) {
    value = x;
    return 1;
}
