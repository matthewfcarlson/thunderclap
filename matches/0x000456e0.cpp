class Obj_456e0 {
  public:
    char pad[0x14];
    int value;
    unsigned char Check();
};
unsigned char Obj_456e0::Check() {
    return value == 4;
}