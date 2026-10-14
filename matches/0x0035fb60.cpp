extern "C" struct Pairs {
    int a;
    int b;
};
extern Pairs __cdecl FUN_002672f0(const char* s, int a, int b);
extern int gA;
extern int gB;
void __cdecl FUN_0035fb60() {
    Pairs r = FUN_002672f0("Template", 0, 0);
    gA = r.a;
    gB = r.b;
}
