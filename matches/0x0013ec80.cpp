class Obj_13ec80 {
  public:
    char pad[0x4c];
    int value;
    char Set(int x);
};

char Obj_13ec80::Set(int x) {
    value = x;
    return 1;
}
