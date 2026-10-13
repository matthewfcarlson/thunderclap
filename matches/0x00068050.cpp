class Obj {
  public:
    char pad[0x28];
    int m28;
    unsigned char Fn(int a);
};
unsigned char Obj::Fn(int a) {
    m28 = a;
    return 1;
}
