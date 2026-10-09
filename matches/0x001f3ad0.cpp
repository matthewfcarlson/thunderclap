struct Child {
    char pad[8];
    int value;
    void FUN(int);
};
struct Obj {
    char pad[0xc8];
    Child* child;
    bool run();
};
bool Obj::run() {
    if (child && child->value) {
        child->FUN(0);
        return true;
    }
    return false;
}