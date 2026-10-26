#include "decls/data/game/global.h"
// data: gZero_8a060 = DAT_003f335c

class Obj_8a060 {
    char pad[0x160];

  public:
    int Find(int);
    char* Get(int);
};
char* Obj_8a060::Get(int arg) {
    int i = Find(arg);
    if (i == -1)
        return (char*)&(*(float*)&DAT_003f335c);
    return (char*)this + 0x160 + i * 0x18;
}