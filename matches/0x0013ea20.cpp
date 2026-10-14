class Obj_13ea20 {
  public:
    char pad[0xc];
    int value;
    char Set(int x);
};

char Obj_13ea20::Set(int x) {
    value = x;
    return 1;
}
