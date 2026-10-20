#include "compat/ptr.h"
extern "C" char DAT_0040bf84[];
struct CScriptParser {
    void* vt;
    int arg;
    int a;
    int b;
    int c;
    unsigned char d;
    unsigned char e;
    CScriptParser(int);
};
CScriptParser::CScriptParser(int x) {
    arg = x;
    vt = (void*)((hulk_intptr)DAT_0040bf84);
    a = 0;
    b = 0;
    c = 0;
    e = 0;
    d = 0;
}
