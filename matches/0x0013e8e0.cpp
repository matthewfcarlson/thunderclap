class Obj {
  public:
    char pad[36];
    char m24;
    char Fn(unsigned char a);
};

char Obj::Fn(unsigned char a) {
    m24 = a;
    return 1;
}