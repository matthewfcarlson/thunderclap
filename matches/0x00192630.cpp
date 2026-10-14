class Obj_192630 {
  public:
    char Set(int v);
    char pad[0x28];
    int value;
};

char Obj_192630::Set(int v) {
    value = v;
    return 1;
}
