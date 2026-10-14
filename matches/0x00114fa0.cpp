class Obj_114fa0 {
  public:
    char pad[0x20];
    int value;
    unsigned char Set(int x);
};

unsigned char Obj_114fa0::Set(int x) {
    value = x;
    return 1;
}
