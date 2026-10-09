class D {
  public:
    void Init();
};
class C {
  public:
    char p[16];
    int state;
    char q[28];
    int m30, m34;
    void Next();
};
extern D* __stdcall Make(int, int, int, int, int, int, int, int);
void __fastcall Target(C* self) {
    if (self->m34 && self->m30) {
        D* x = Make(0x40914c, 0x40915c, 0x3f335c, 0x408ee8, 0x408fa0, 2, 0, 0);
        x->Init();
        self->state = 0x13;
        self->Next();
    }
}
