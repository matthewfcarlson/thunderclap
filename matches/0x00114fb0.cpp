class Obj_114fb0 {
  public:
    char pad[0xc];
    char mValue;
    unsigned char Fn(char value);
};

unsigned char Obj_114fb0::Fn(char value) {
    mValue = value;
    return 1;
}
