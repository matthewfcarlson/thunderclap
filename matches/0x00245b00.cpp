struct Ctx;
struct Parser {
    char pad[0x90];
    int line;
};
bool F2(Ctx* c, const char* s, ...);
int vfmt(char* buf, int n, const char* fmt, char* va);
bool Err(Parser* p, Ctx* c, const char* fmt, ...) {
    char buf[0x1000];
    vfmt(buf, 0x1000, fmt, (char*)&fmt + 4);
    F2(c, buf);
    F2(c, "\nError Line: [%d]\n", p->line);
    return false;
}
