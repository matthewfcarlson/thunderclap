extern int __cdecl FUN_00246f50(void*, const char*, const char*);
int __cdecl FUN_0025aa50(void** value, char flag) {
    const char* s = "true";
    if (!flag)
        s = "false";
    void* v = *value;
    return FUN_00246f50(v, "%s", s);
}