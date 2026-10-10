extern const char* const gNames[21];
char* __cdecl Make(void* a, const char* b, int c);
void __cdecl Target(void* param) {
    int i = 0;
    do {
        const char* p = gNames[i];
        const char* e = p + 1;
        char c;
        do {
            c = *p;
            p++;
        } while (c != 0);
        char* r = Make(param, gNames[i], (int)(p - e));
        r[5] |= 0x20;
        r[6] = (char)(i + 1);
        i++;
    } while (i < 21);
}
