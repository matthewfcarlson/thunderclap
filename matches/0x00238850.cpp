class Obj_238850 {
  public:
    char pad[0xc];
    int value;
    char Set(int x);
};

char Obj_238850::Set(int x) {
    value = x;
    return 1;
}
