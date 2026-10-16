// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 16/16)
// FUN_00240280 @ 0x00240280
#include "decls/data/engine/audio.h"

struct StringHeader_240280 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_240280*);
struct String {
    char* data; unsigned short kind; unsigned short pad6; unsigned short length; unsigned short pad10;
    void FUN_00240090(const String* src);
    char* FUN_0023fbb0();
    String* ToUpper(String* out);
};
String* String::ToUpper(String* out) {
    String tmp;
    tmp.FUN_00240090(this);
    char* p = tmp.FUN_0023fbb0();
    if (p) {
        while (*p) {
            if (*p >= 'a' && *p <= 'z') *p -= 0x20;
            ++p;
        }
    }
    out->FUN_00240090(&tmp);
    if (tmp.kind == 2) {
        StringHeader_240280* header = reinterpret_cast<StringHeader_240280*>(tmp.data) - 1;
        if (header->references == 1) {
            if (tmp.data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    return out;
}
