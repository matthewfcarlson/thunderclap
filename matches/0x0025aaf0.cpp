extern int __cdecl FUN_00246f50(int, const char*, int);
int __cdecl FUN_0025aaf0(const int* value, unsigned char flag) {
    int n = *value;
    unsigned int f = flag;
    return FUN_00246f50(n, "%d", f);
}