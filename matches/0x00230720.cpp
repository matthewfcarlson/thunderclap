// Same code shape as 0x0022d210 (propagated; names are from that function)
struct Obj_230720 {
    unsigned int x[3];
    void F(Obj_230720*);
};
struct Arg_230720 {
    void Helper(Obj_230720*, unsigned int*);
};
void Obj_230720::F(Obj_230720* a) {
    unsigned int t[3];
    ((Arg_230720*)a)->Helper(this, t);
    x[0] = t[0];
    x[1] = t[1];
    x[2] = t[2];
}