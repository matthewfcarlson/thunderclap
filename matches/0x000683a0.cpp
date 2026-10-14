class Obj_683a0 {
  public:
    char pad[0x20];
    int m;
    char Set(int value) throw();
};

char Obj_683a0::Set(int value) throw() {
    m = value;
    return 1;
}