struct Obj_309820 {
    int x;
    void helper();
    int* target();
};
int* Obj_309820::target() {
    helper();
    return &x + 1;
}