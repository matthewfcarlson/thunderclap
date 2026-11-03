#include "decls/data/game/unknown.h"
// data: fmt_1f8f40 = DAT_003f3f38
#include "gen/owners.h"

extern void __cdecl FUN_00267760(char*, int, const char*, const char*);
struct Sub_1f8f40 {
};
void owners::Target_1f8f40::FUN_001f8f40(const char* arg) {
    ((owners::Target_27b040 *)(((Sub_1f8f40*)((char*)this + 8))))->FUN_0027b040((hulk_uintptr)arg);
    FUN_00267760((char*)this + 0x41c, 0x20, DAT_003f3f38, arg);
}