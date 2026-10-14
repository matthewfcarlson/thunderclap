class Manager_bc750 {
  public:
    void A(int);
    void* B();
    void C(int);
    void D(void*);
};
class Other_bc750 {
  public:
    void F(void*);
    void H(int);
};
class Obj_bc750 {
  public:
    char pad0[0x34];
    Manager_bc750* m34;
    Other_bc750* m38;
    char pad40[0x10];
    Other_bc750* m4c;
    int Get(void*);
    void End();
};
void Tail();
void Obj_bc750::End() {
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
