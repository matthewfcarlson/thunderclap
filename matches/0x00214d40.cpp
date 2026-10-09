extern int __cdecl FUN_00217600(int, void*);
extern void __cdecl FUN_00214c90(int, int, const char*);
void __cdecl FUN_00214d40(int a, int b, int c)
{
    char local[8];
    int r = FUN_00217600(b, local);
    int v;
    if (r == 0) {
        v = b;
    } else {
        v = c;
    }
    FUN_00214c90(a, v, "perform arithmetic on");
}
