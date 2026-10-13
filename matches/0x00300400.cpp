class Obj {
  public:
    char pad[0x40];
    int a;
    int b;
    void Copy();
};
void Obj::Copy() {
    b = a;
}
