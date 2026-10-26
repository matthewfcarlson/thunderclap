#include "decls/data/engine/movie.h"
// data: gAlloc = DAT_0055dbb0

#include "compat/ptr.h"
extern "C" char* strcpy(char*, const char*);
extern "C" unsigned int strlen(const char*);
class Alloc {
  public:
    char* Allocate(hulk_uintptr, int);
};
class Obj {
    char pad[12];
    char* text;

  public:
    void Set(const char* s);
};
void Obj::Set(const char* s) {
    text = (*(Alloc*)&DAT_0055dbb0).Allocate(strlen(s) + 1, 4);
    strcpy(text, s);
}