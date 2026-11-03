#include "decls/data/engine/movie.h"
// data: gAlloc = DAT_0055dbb0

#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char* strcpy(char*, const char*);
extern "C" unsigned int strlen(const char*);
class Alloc {
  public:
};
void owners::Obj_3352c0::FUN_003352c0(const char* s) {
    text = ((char *)((owners::Allocator_337d60 *)&((*(Alloc*)&DAT_0055dbb0)))->FUN_00337d60((unsigned int)(strlen(s) + 1), 4));
    strcpy(text, s);
}