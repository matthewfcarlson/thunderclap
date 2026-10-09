struct Obj {
    void f();
};
extern Obj g;
void wrapper() {
    g.f();
}