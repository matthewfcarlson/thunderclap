class Obj_11bfb0 {
  public:
    char pad[0x30];
    int value;
    unsigned char Set(int x);
};
unsigned char Obj_11bfb0::Set(int x) {
    value = x;
    return 1;
}