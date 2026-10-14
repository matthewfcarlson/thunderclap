struct Obj_22d210 {
    unsigned int x[3];
    void F(Obj_22d210*);
};
struct Arg_22d210 {
    void Helper(Obj_22d210*, unsigned int*);
};
void Obj_22d210::F(Obj_22d210* a) {
    unsigned int t[3];
    ((Arg_22d210*)a)->Helper(this, t);
    x[0] = t[0];
    x[1] = t[1];
    x[2] = t[2];
}