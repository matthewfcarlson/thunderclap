class Obj_16ec10 {
  public:
    char pad[0x40];
    int value;
    unsigned char Set(int x);
};

unsigned char Obj_16ec10::Set(int x) {
    value = x;
    return 1;
}