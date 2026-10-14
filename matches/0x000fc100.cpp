typedef unsigned int u32_fc100;
struct Obj_fc100 {
    void F5(u32_fc100, u32_fc100);
    void F0(u32_fc100);
};
extern Obj_fc100* gObj_fc100;
void Target(u32_fc100 a, u32_fc100 b) {
    gObj_fc100->F5(a, b);
    gObj_fc100->F0(a);
}
