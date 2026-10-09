typedef unsigned char bool8;
struct Obj { int pad[6]; int a; int b; };
extern const char UID[];
extern bool8 __cdecl Check(int, const char *);
extern bool8 __cdecl Match(int *, int, int);
int __cdecl Target(int *p, Obj *o) {
    int a;
    int b;
    if (o) { a = o->a; b = o->b; }
    else { a = 0; b = 0; }
    if (Check(*p, UID) && Match(p, a, b)) return 1;
    return 0;
}