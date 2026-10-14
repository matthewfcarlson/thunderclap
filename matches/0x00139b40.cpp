class Obj_139b40 {
  public:
    char pad[0x40];
    int value;
    char Set(int x);
};

char Obj_139b40::Set(int x) {
    value = x;
    return 1;
}
