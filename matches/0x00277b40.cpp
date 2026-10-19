unsigned int __cdecl FUN_002698b0(char*);
struct Helper_277b40 {
    unsigned int f(unsigned int, unsigned int);
};
struct C_277b40 {
    unsigned int f(char*, unsigned int);
};
unsigned int C_277b40::f(char* param_1, unsigned int param_2) {
    if (*param_1 == '\\')
        ++param_1;
    unsigned int x = FUN_002698b0(param_1);
    return ((Helper_277b40*)this)->f(x, param_2);
}