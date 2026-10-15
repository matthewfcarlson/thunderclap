extern "C" char __cdecl parse(const char*, const char*, char*);
extern "C" char __cdecl parse2(const char*, const char*);
class Reader {
  public:
    char consume(char**);
};
char test(char** s, char* p, Reader* r) {
    char* value = *s;
    if (parse(value, "%s ", p) && r->consume(s)) {
        value = *s;
        return parse2(value, "\n");
    }
    return 0;
}
