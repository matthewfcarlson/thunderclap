// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/13)
// FUN_003378c0 @ 0x003378c0
#include "decls/data/engine/movie.h"

extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);

struct Context {
    char* FUN_00338a10();
};

struct ParseError {
    char pad0[4];
    unsigned int code;
    Context* context;
};

const char* __fastcall FUN_003378c0(ParseError* err) {
    DAT_0055ddc0[0] = 0;
    const char* name;
    if (err->context == 0 || (name = err->context->FUN_00338a10()) == 0)
        name = "<?>";
    const char* fmt;
    switch (err->code) {
    case 0:
        return "No error.";
    case 1:
        return "Hit EOF, no error.";
    case 2:
        return "Ending quotation \" expected.";
    case 3:
        return "Token size is too big. Did you forget a quotation?";
    case 4:
        fmt = "Syntax error, bad command '%s'.";
        break;
    case 5:
        fmt = "No object definition found for '%s'.";
        break;
    case 6:
        fmt = "No attribute definition found for '%s'.";
        break;
    default:
        return "Unknown Error...something is really wrong";
    }
    sprintf(DAT_0055ddc0, fmt, name);
    return DAT_0055ddc0;
}
