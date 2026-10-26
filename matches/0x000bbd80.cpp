#include "decls/data/game/unknown.h"
// data: gFlag = DAT_004dd83a

class Obj {
  public:
    char pad[4];
    void* ptr;
    void Set(void* p);
};
void Obj::Set(void* p) {
    if (ptr)
        (*(unsigned char*)&DAT_004dd83a) = (p == 0);
}