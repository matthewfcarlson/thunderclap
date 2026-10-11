class Manager {
  public:
    void A(int);
    void* B();
    void C(int);
    void D(void*);
};
class Other {
  public:
    void F(void*);
    void H(int);
};
class Obj {
  public:
    char pad0[0x34];
    Manager* m34;
    Other* m38;
    char pad40[0x10];
    Other* m4c;
    int Get(void*);
    void End();
};
void Tail();
void Obj::End() {
    if (m34 && m38) {
        m38->H(9);
        m34->A(0);
        void* edi = m34->B();
        if (edi) {
            int ebx = Get(edi);
            if (ebx) {
                if (m4c)
                    m4c->F(edi);
                m34->C(ebx);
                m34->D(edi);
                Tail();
            }
        }
    }
}
