typedef unsigned int u32;
struct Obj {
    void F5(u32, u32);
    void F0(u32);
};
extern Obj* gObj;
void Target(u32 a, u32 b) {
    gObj->F5(a, b);
    gObj->F0(a);
}
