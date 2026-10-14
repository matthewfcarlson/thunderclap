class Obj_133390 {
  public:
    char pad[0x1c];
    int value;
    unsigned char Set(int x);
};

unsigned char Obj_133390::Set(int x) {
    value = x;
    return 1;
}
