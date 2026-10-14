extern "C" int strcmp(const char*, const char*);
int Find(const char* s, const char** list) {
    int i = 0;
    const char* p = list[0];
    while (p) {
        if (strcmp(p, s) == 0)
            return i;
        p = list[++i];
    }
    return -1;
}