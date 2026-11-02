extern "C" int strcmp(const char*, const char*);
extern "C" unsigned int strlen(const char*);
extern "C" bool FUN_0008d880(const char* a, const char* b) {
    if (!a)
        return false;
    if (!b)
        return false;
    int la = (int)strlen(a), lb = (int)strlen(b);
    if (la < lb)
        return false;
    return strcmp(a + la - lb, b) == 0;
}