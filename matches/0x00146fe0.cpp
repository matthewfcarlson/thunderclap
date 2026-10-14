class Obj_146fe0 {
  public:
    char pad[0x48];
    int value;
    char Set(int x);
};

char Obj_146fe0::Set(int x) {
    value = x;
    return 1;
}
