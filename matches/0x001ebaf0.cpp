#include "decls/data/game/unknown.h"
// data: g_lang = DAT_0049caa4
#include "gen/owners.h"

extern "C" int strcmp(const char*, const char*);
struct S7 {
    char c[7];
};
struct S8_1ebaf0 {
    char c[8];
};
struct Obj_1ebaf0 {
    char d[12];
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
    Use(((Obj_1ebaf0 *)((owners::String_23fc40 *)&o)->FUN_0023fc40(DAT_0049caa4, (hulk_intptr)2)));
    ((owners::Str_240060 *)&o)->FUN_00240060();
}
