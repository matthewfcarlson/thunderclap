#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"
// data: yesStr = DAT_00429b50

extern "C" char* __cdecl getText(char*);
extern "C" int __cdecl strcmp(const char*, const char*);
char* __cdecl target(char* p) {
    char* a = getText(p);
    char* b = getText(p);
    return strcmp(a, b) ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}