#include "decls/data/engine/movie.h"
// data: gHeap = DAT_0055dbb0

#include "compat/ptr.h"
extern "C" unsigned strlen(const char*);
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
class Source {
  public:
    char* Lookup();
};
class Heap {
  public:
    void* Allocate(hulk_uintptr, unsigned);
};
bool __stdcall Get(char** out, Source* src, int b, int c) {
    char* s = src->Lookup();
    if (!s)
        return false;
    char* d = (char*)(*(Heap*)&DAT_0055dbb0).Allocate(strlen(s) + 1, 4);
    *out = d;
    copy(d, s);
    return true;
}