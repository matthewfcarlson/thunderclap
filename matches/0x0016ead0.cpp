class Obj_16ead0 {
  public:
    char pad[12];
    int value;
    char Set(int x);
};
char Obj_16ead0::Set(int x) {
    value = x;
    return 1;
}
