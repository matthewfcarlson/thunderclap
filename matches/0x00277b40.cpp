unsigned int __cdecl FUN_002698b0(char *);
struct Helper { void f(unsigned int, unsigned int); };
struct C { void f(char *, unsigned int); };
void C::f(char *param_1, unsigned int param_2) {
    if (*param_1 == '\\') ++param_1;
    unsigned int x = FUN_002698b0(param_1);
    ((Helper*)this)->f(x, param_2);
}