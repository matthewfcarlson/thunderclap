class Obj_1fb950 {
  public:
    char pad[0xcd];
    unsigned char a;
    char pad2;
    unsigned char b;
    int c;
};
void __fastcall target(Obj_1fb950* p) {
    p->a = p->b;
    p->c = 0;
}