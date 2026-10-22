class Arg_e7cd0 {
  public:
    char F90();
    unsigned int FAB();
    char FEF();
    void F30();
    char F50();
    unsigned int FB1();
    void FFB();
    void FA0();
};
class Out_e7cd0 {
  public:
    virtual void Fn(Arg_e7cd0*, unsigned int);
};
class FEThingsBase_e7cd0 {
  public:
    char pad[0x2220];
    char flag;
    void Target(Arg_e7cd0*, Out_e7cd0*);
};
void FEThingsBase_e7cd0::Target(Arg_e7cd0* arg, Out_e7cd0* out) {
    bool b = false;
    char c = arg->F90();
    while (c) {
        unsigned int x = arg->FAB();
        if (x == 0x27a5e803) {
            if (flag)
                b = true;
        } else if (x == 0x46ddcbb4 && !flag)
            b = true;
        c = arg->F90();
    }
    if (arg->FEF()) {
        arg->F30();
        if (arg->F50()) {
            do {
                unsigned int v = arg->FB1();
                if (b) {
                    if (!out) {
                        arg->FA0();
                        break;
                    }
                    out->Fn(arg, v);
                }
            } while (arg->F50());
        }
        arg->FFB();
    }
}