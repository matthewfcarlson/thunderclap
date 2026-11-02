extern "C" char __cdecl parse(const char*, const char*, char*);
extern "C" char __cdecl parse2(const char*, const char*);
class Reader {
  public:
    char consume(char**);
};
extern "C" char FUN_00252c90(char** s, char* p, void * r) {
    char* value = *s;
    if (parse(value, "%s ", p) && ((Reader *)r)->consume(s)) {
        value = *s;
        return parse2(value, "\n");
    }
    return 0;
}
