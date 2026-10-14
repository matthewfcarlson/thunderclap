unsigned int __cdecl FUN_002698b0(char*);
struct Helper_277b40 {
    void f(unsigned int, unsigned int);
};
struct C_277b40 {
    void f(char*, unsigned int);
};
void C_277b40::f(char* param_1, unsigned int param_2) {
    if (*param_1 == '\\')
        ++param_1;
    unsigned int x = FUN_002698b0(param_1);
    ((Helper_277b40*)this)->f(x, param_2);
}