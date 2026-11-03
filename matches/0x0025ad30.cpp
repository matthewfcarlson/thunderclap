// FUN_0025ad30 @ 0x0025ad30
// 0x0025ad30: compare the text of a (copied) string with the string stored in b, strcmp style
#include "gen/owners.h"
extern "C" int __cdecl strcmp(const char*, const char*);

struct Str_25ad30 {
    char data[12];
    const char* FUN_0023fb00();
};

struct Record_25ad30 {
    char pad00[0x10];
    Str_25ad30 name;
};

extern "C" int FUN_0025ad30(void * a, void * b)
{
    Str_25ad30 copy;
    Str_25ad30* t = ((Str_25ad30 *)((owners::String_23fc40 *)&copy)->FUN_0023fc40(((Str_25ad30 *)a)->FUN_0023fb00(), (hulk_intptr)0));
    const char* other = ((Record_25ad30 *)b)->name.FUN_0023fb00();
    int result = strcmp(t->FUN_0023fb00(), other);
    ((owners::Str_240060 *)&copy)->FUN_00240060();
    return result;
}
