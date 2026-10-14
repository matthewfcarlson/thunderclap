class Obj_5a100 {
  public:
    char pad[0x74];
    int value;
    char Set(int x);
};

char Obj_5a100::Set(int x) {
    value = x;
    return 1;
}
