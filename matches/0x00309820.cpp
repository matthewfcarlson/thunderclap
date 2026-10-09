struct Obj {
    int x;
    void helper();
    int* target();
};
int* Obj::target() {
    helper();
    return &x + 1;
}