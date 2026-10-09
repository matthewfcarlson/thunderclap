typedef unsigned int U;
extern int __cdecl GetType(int, int);
extern int __cdecl GetName(int, int);
extern int __cdecl Format(int, const char *, int, int);
extern void __cdecl Report(int, int, int);
void __cdecl Target(int a, int b, int c)
{
    int x = GetType(a, b);
    if (x != c) {
        int y = GetName(a, c);
        int z = GetType(a, b);
        z = GetName(a, z);
        z = Format(a, "%s expected, got %s", y, z);
        Report(a, b, z);
    }
}
