class Obj {
  public:
    char pad[20];
    char m14;
    unsigned char Fn(unsigned char a);
};
unsigned char Obj::Fn(unsigned char a) {
    m14 = a;
    return 1;
}
