// Same code shape as 0x0022d210 (propagated; names are from that function)
struct Obj_22d260 {
    unsigned int x[3];
    void F(Obj_22d260*);
};
struct Arg_22d260 {
    void Helper(Obj_22d260*, unsigned int*);
};
void Obj_22d260::F(Obj_22d260* a) {
    unsigned int t[3];
    ((Arg_22d260*)a)->Helper(this, t);
    x[0] = t[0];
    x[1] = t[1];
    x[2] = t[2];
}