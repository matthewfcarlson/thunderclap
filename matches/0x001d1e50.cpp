// b..d: a vector passed by value (FUN_001d0870 copies its three words).
struct Vec3_1d1e50 {
    float x, y, z;
};
struct Obj_1d1e50 {
    char pad[8];
    int member;
    bool run(int a, Vec3_1d1e50 b);
};
void f1(int, int);
void f2(int, Vec3_1d1e50*);
void f3(int, int);
bool Obj_1d1e50::run(int a, Vec3_1d1e50 b) {
    f1(member, a);
    f2(member, &b);
    f3(member, -3);
    return true;
}