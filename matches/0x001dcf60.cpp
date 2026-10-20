#include "compat/ptr.h"
struct Data_1dcf60 {
    char pad[0x74];
    hulk_intptr p;
};
class Obj_1dcf60 {
  public:
    Data_1dcf60* Get();
    char Check();
};
class CGrabAction {
  public:
    char pad[0x1e620];
    Obj_1dcf60* items[128];
    int count;
    void Set(char value);
};
void CGrabAction::Set(char value) {
    int i = 0;
    while (i < count) {
        Obj_1dcf60* o = items[i];
        Data_1dcf60* d = o->Get();
        if (d && !o->Check()) {
            d = o->Get();
            if (d->p)
                *((char*)d->p + 0x72) = value;
        }
        ++i;
    }
}
