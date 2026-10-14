struct Ctx_261500 {
    char pad[0x2004];
    char* out;
};
const char* Next(Ctx_261500*);
char* Fn(Ctx_261500* c) {
    char* start = c->out;
    *start = 0;
    char* d = start;
    const char* s = Next(c);
    while (*s) {
        c->out = d;
        const char* p = s;
        char ch = *p;
        while (ch) {
            *d = ch;
            p++;
            d++;
            c->out = c->out + 1;
            ch = *p;
        }
        s = Next(c);
    }
    *d = 0;
    c->out++;
    return start;
}
