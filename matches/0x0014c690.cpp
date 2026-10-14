class Obj_14c690 {
  public:
    char pad[0xc];
    int value;
    char Set(int x);
};

char Obj_14c690::Set(int x) {
    value = x;
    return 1;
}
