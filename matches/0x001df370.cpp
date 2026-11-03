#include "gen/owners.h"
class Obj {
  public:
    char pad[0x70];
    char flag;
};
class Mid {
  public:
    char pad[0x74];
    Obj* obj;
};
struct ThisWrap_001df370 {
    Mid* Find(int);
    char Target(int id);
};
char ThisWrap_001df370::Target(int id) {
    Mid* p = this->Find(id);
    if (!p)
        return 0;
    p = ((Mid *)((owners::C_1d72e0 *)p)->FUN_001d72e0());
    if (!p)
        return 0;
    Obj* q = p->obj;
    if (!q)
        return 0;
    return q->flag;
}