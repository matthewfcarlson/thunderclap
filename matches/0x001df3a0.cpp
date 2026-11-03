#include "gen/owners.h"
class Obj {
  public:
    char pad[0x70];
    char flag;
    char gap[3];
    Obj* link;
};
struct ThisWrap_001df3a0 {
    Obj* findObj(int);
    char target(int id, char value);
};
char ThisWrap_001df3a0::target(int id, char value) {
    Obj* a = this->findObj(id);
    if (!a)
        return 0;
    Obj* b = ((Obj *)((owners::C_1d72e0 *)a)->FUN_001d72e0());
    if (!b)
        return 0;
    Obj* c = b->link;
    if (!c)
        return 0;
    c->flag = value;
    return 1;
}