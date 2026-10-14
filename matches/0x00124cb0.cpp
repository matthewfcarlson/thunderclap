struct B_124cb0 {
    int h();
    void j();
};
struct A_124cb0 {
    A_124cb0* f();
    B_124cb0* g();
};
struct ClearProjectileDistanceAction {
    char pad[0x20];
    A_124cb0* mThing;
    void vfunc_4();
};
void ClearProjectileDistanceAction::vfunc_4() {
    B_124cb0* x = mThing->f()->g();
    if (x->h())
        x->j();
}