extern "C" int strcmp(const char*, const char*);
struct S7 {
    char c[7];
};
struct S8 {
    char c[8];
};
struct Obj {
    char d[12];
    Obj* Make(const char*, int);
    void Cleanup();
};
extern char g_lang[8];
void Use(void*);
void __stdcall Fn(const char* s) {
    Obj o;
    if (strcmp(s, "fr") == 0) {
        *(S7*)g_lang = *(const S7*)"french";
    } else if (strcmp(s, "it") == 0) {
        *(S8*)g_lang = *(const S8*)"italian";
    } else {
        *(S8*)g_lang = *(const S8*)"english";
    }
    Use(o.Make(g_lang, 2));
    o.Cleanup();
}
