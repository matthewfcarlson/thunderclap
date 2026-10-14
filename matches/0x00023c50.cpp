class Obj {
  public:
    char pad[0x1d40];
    unsigned char member;
    void Fn(unsigned char x);
};
void Obj::Fn(unsigned char x) {
    member = x;
}
