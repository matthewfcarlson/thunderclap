#include "gen/owners.h"
extern "C" void __cdecl FUN_00267760(char*, unsigned int, const char*, const char*);
void owners::Obj_36d60::FUN_00036d60(const char* arg) {
    FUN_00267760((char*)this + 0x20b8, 0x40, "%s", arg);
    ((owners::Obj_36d60*)((char*)this + 8))->Finish(arg);
}