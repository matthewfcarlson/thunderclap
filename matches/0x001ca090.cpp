#include "decls/data/game/global.h"
// data: checkpoint = DAT_00421ba0

class Thing_1ca090 {
  public:
    bool ready();
    void mark(const char*, int);
    void finish();
};
Thing_1ca090* GetThing();
class Owner_1ca090 {
  public:
    char pad[0x14];
    int value;
    bool run();
};
bool Owner_1ca090::run() {
    Thing_1ca090* t = GetThing();
    if (!t)
        return false;
    if (!t->ready())
        return false;
    t->mark(DAT_00421ba0, value);
    t->finish();
    return true;
}