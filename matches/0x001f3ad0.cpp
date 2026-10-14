struct Child_1f3ad0 {
    char pad[8];
    int value;
    void FUN(int);
};
struct Obj_1f3ad0 {
    char pad[0xc8];
    Child_1f3ad0* child;
    bool run();
};
bool Obj_1f3ad0::run() {
    if (child && child->value) {
        child->FUN(0);
        return true;
    }
    return false;
}