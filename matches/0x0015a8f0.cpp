class Obj_15a8f0 {
  public:
    char pad[0x14];
    int value;
    char Set(int x);
};

char Obj_15a8f0::Set(int x) {
    value = x;
    return 1;
}
