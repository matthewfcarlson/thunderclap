extern int vtable;
class SeqEventVarPitchRand {
public:
    void init();
    SeqEventVarPitchRand();
    int vptr;
    int unused;
    int a;
    int b;
};
SeqEventVarPitchRand::SeqEventVarPitchRand() {
    init();
    vptr = (int)&vtable;
    a = 0x3f4ccccd;
    b = 0x3f99999a;
}
