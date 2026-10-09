class Obj {
  public:
    int pad;
    unsigned int value;
};
int __fastcall target(Obj* p) {
    return (p->value & 0x5e) == 0;
}