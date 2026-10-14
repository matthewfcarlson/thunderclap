struct Other_1c3800 {
    void f(int, int, int, int, int);
};
struct Obj_1c3800 {
    char pad[0x14];
    Other_1c3800* value;
    void run(int, int, int, int, int);
};
void Obj_1c3800::run(int a, int b, int c, int d, int e) {
    if (value)
        value->f(a, b, c, d, e);
}