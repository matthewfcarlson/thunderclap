// FUN_00170130 @ 0x00170130
#include "compat/ptr.h"
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*);
extern "C" char* __cdecl FUN_0008d6d0(hulk_uintptr);
class StrHolder_170130 {
public:
    char pad[40];
    char* text;
    int length;
    bool FUN_00170130(const char* src, int len);
};
bool StrHolder_170130::FUN_00170130(const char* src, int len) {
    thunk_FUN_00267090(text);
    if (src != 0 && len > 0) {
        text = FUN_0008d6d0(len + 1);
        memcpy(text, src, len);
        text[len] = 0;
        length = len;
        return true;
    }
    text = 0;
    length = 0;
    return true;
}
