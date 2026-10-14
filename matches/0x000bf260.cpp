extern "C" char DAT_003f335c[];
extern "C" char DAT_00408ee8[];
extern "C" char DAT_00408fa0[];
extern "C" char DAT_0040914c[];
extern "C" char DAT_0040915c[];
class D {
  public:
    void Init();
};
class C_bf260 {
  public:
    char p[16];
    int state;
    char q[28];
    int m30, m34;
    void Next();
};
extern D* __stdcall Make(int, int, int, int, int, int, int, int);
void __fastcall Target(C_bf260* self) {
    if (self->m34 && self->m30) {
        D* x = Make(((int)DAT_0040914c), ((int)DAT_0040915c), ((int)DAT_003f335c), ((int)DAT_00408ee8), ((int)DAT_00408fa0), 2, 0, 0);
        x->Init();
        self->state = 0x13;
        self->Next();
    }
}
