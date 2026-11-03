#include "decls/data/engine/movie.h"
// data: gHeap = DAT_0055dbb0

#include "compat/ptr.h"
#include "gen/owners.h"
class Lookup {
  public:
    char* Get();
};
class Heap {
  public:
};
extern "C" unsigned strlen(const char*);
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c);
}
extern "C" bool __stdcall FUN_00336430(char** out, Lookup* lookup, int a, int b) {
    char* s = lookup->Get();
    if (!s)
        return false;
    char* d = ((char *)((owners::Allocator_337d60 *)&((*(Heap*)&DAT_0055dbb0)))->FUN_00337d60((unsigned int)(strlen(s) + 1), 4));
    *out = d;
    Copy(d, s);
    return true;
}