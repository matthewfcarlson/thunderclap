class Obj_23cb40 {
  public:
    char pad[12];
    unsigned char value;
    char SetPS2_0023cb40(unsigned char b);
};

char Obj_23cb40::SetPS2_0023cb40(unsigned char b) {
    value = b;
    return 1;
}