extern int __cdecl FUN_00246f50(const char*, const char*, int);
int __cdecl FUN_0025aab0(const char** value, signed char number) {
    int n = number;
    const char* s = *value;
    return FUN_00246f50(s, "%d", n);
}