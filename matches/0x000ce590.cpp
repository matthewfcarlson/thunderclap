#include "gen/owners.h"
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Thing_ce590 {
    char pad[0x264];

  public:
    void Finish();
    void SetName(const char* s);
};
void Thing_ce590::SetName(const char* s) {
    ((owners::Obj_cac60 *)this)->FUN_000cac60();
    strncpy((char*)this + 0x264, s, 0x40);
    Finish();
}