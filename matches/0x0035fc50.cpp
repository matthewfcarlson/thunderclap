struct Pair {
    unsigned int a;
    unsigned int b;
};
extern "C" Pair __cdecl Hash(const char*, unsigned int, unsigned int);
extern unsigned int gA;
extern unsigned int gB;
void __cdecl FUN_0035fc50() {
    Pair p = Hash("Template", 0, 0);
    gA = p.a;
    gB = p.b;
}
