extern "C" int strcmp(const char*, const char*);
struct S7 {
    char c[7];
};
struct S8_1ebaf0 {
    char c[8];
};
struct Obj_1ebaf0 {
    char d[12];
    Obj_1ebaf0* Make(const char*, int);
    void Cleanup();
};
extern char g_lang[8];
void Use(void*);
void __stdcall Fn(const char* s) {
    Obj_1ebaf0 o;
    if (strcmp(s, "fr") == 0) {
        *(S7*)g_lang = *(const S7*)"french";
    } else if (strcmp(s, "it") == 0) {
        *(S8_1ebaf0*)g_lang = *(const S8_1ebaf0*)"italian";
    } else {
        *(S8_1ebaf0*)g_lang = *(const S8_1ebaf0*)"english";
    }
    Use(o.Make(g_lang, 2));
    o.Cleanup();
}
