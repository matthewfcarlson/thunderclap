#include "decls/data/game/unknown.h"
// data: g_lang = DAT_0049caa4

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
void Use(void*);
void __stdcall Fn(const char* s) {
    Obj_1ebaf0 o;
    if (strcmp(s, "fr") == 0) {
        *(S7*)DAT_0049caa4 = *(const S7*)"french";
    } else if (strcmp(s, "it") == 0) {
        *(S8_1ebaf0*)DAT_0049caa4 = *(const S8_1ebaf0*)"italian";
    } else {
        *(S8_1ebaf0*)DAT_0049caa4 = *(const S8_1ebaf0*)"english";
    }
    Use(o.Make(DAT_0049caa4, 2));
    o.Cleanup();
}
