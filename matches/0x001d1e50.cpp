struct Obj_1d1e50 {
    char pad[8];
    int member;
    bool run(int a, int b, int c, int d);
};
void f1(int, int);
void f2(int, int*);
void f3(int, int);
bool Obj_1d1e50::run(int a, int b, int c, int d) {
    f1(member, a);
    f2(member, &b);
    f3(member, -3);
    return true;
}