class Obj_300400 {
  public:
    char pad[0x40];
    int a;
    int b;
    void Copy();
};
void Obj_300400::Copy() {
    b = a;
}
