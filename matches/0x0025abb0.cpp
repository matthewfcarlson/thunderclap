extern "C" int __cdecl FUN_00246f50(unsigned int, const char*, unsigned int);
int __cdecl FUN_0025abb0(const unsigned int* value, unsigned int arg) {
    unsigned int x = *value;
    return FUN_00246f50(x, "%u", arg);
}