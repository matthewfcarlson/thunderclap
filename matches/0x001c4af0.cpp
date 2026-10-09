extern int gA;
extern int gB;
struct Obj { char pad[8]; int a; int b; };
int __fastcall target(Obj* p) {
    if (p->a == gA && p->b == gB) return 1;
    return 0;
}