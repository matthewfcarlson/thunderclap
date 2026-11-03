#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: gPointer = DAT_004cc02c, gZero_240110 = DAT_003f335c
#include "gen/owners.h"

extern "C" void* memcpy(void*, const void*, unsigned int);
class Obj_240110 {
  public:
};
struct Source_240110 {
    char* data;
    char pad[4];
    unsigned short length;
};
void __cdecl FUN_00240110(Obj_240110* obj, Source_240110* src, unsigned int n) {
    __declspec(align(8)) char local[256];
    unsigned int len = src->length;
    unsigned int offset;
    if (len < n) {
        offset = 0;
        n = len + 1;
    } else {
        offset = len - n + 1;
    }
    char* data = src->data;
    if (data == (*(char**)&DAT_004cc02c))
        data = ((char*)&DAT_003f335c);
    memcpy(local, data + offset, n);
    ((owners::String_23fe50 *)obj)->FUN_0023fe50(local);
}