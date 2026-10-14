struct Obj_1d1d90 {
    int pad[2];
    int member;
    bool Target(int, int);
};
extern void __cdecl F1(int, int);
extern void __cdecl F2(int, int);
extern void __cdecl F3(int, int);
bool Obj_1d1d90::Target(int a, int b) {
    F1(member, a);
    F2(member, b);
    F3(member, -3);
    return true;
}