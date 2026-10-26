#include "decls/data/engine/movie.h"
// data: gHeap = DAT_0055dbb0

#include "compat/ptr.h"
class Lookup {
  public:
    char* Get();
};
class Heap {
  public:
    char* Alloc(hulk_uintptr, int);
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
    char* d = (*(Heap*)&DAT_0055dbb0).Alloc(strlen(s) + 1, 4);
    *out = d;
    Copy(d, s);
    return true;
}