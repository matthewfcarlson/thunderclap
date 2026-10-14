class Obj_48100 {
  public:
    char pad[12];
    unsigned char value;
    unsigned char Set(unsigned char x);
};
unsigned char Obj_48100::Set(unsigned char x) {
    value = x;
    return 1;
}