class Obj_16ee70 {
  public:
    char pad[0x20];
    int value;
    char Set(int x);
};

char Obj_16ee70::Set(int x) {
    value = x;
    return 1;
}
