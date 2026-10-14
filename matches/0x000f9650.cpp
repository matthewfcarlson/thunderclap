struct Inner_f9650 {
    void Call(int, int, int, int);
};
struct Obj_f9650 {
    char pad[0x284];
    Inner_f9650* p;
    void Target(int a, int b, int c);
};
void Obj_f9650::Target(int a, int b, int c) {
    p->Call(a, b, c, 1);
}