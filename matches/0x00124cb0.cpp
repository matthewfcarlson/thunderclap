struct B {
    int h();
    void j();
};
struct A {
    A* f();
    B* g();
};
struct ClearProjectileDistanceAction {
    char pad[0x20];
    A* mThing;
    void vfunc_4();
};
void ClearProjectileDistanceAction::vfunc_4() {
    B* x = mThing->f()->g();
    if (x->h())
        x->j();
}