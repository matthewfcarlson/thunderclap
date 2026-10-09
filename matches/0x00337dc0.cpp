extern "C" int strcmp(const char*, const char*);
extern const char* g_tab[11];
int Find(const char* s) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(s, g_tab[i]) == 0)
            return i;
    }
    return -1;
}
