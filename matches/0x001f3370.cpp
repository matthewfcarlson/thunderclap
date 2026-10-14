extern int __cdecl Find(int, int);
extern void __cdecl Act(int, int, int, int, int);
struct Obj_1f3370 {
    int pad;
    volatile int member;
    int target(int arg);
};
int Obj_1f3370::target(int arg) {
    int p = member;
    if (p == 0)
        return 0;
    int found = Find(p, arg);
    if (found == 0)
        return 0;
    Act(member, found, 1, 0, 0);
    return 1;
}