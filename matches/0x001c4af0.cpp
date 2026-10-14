extern int gA_1c4af0;
extern int gB_1c4af0;
struct Obj_1c4af0 {
    char pad[8];
    int a;
    int b;
};
int __fastcall target(Obj_1c4af0* p) {
    if (p->a == gA_1c4af0 && p->b == gB_1c4af0)
        return 1;
    return 0;
}