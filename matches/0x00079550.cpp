#include "decls/data/game/global.h"
// data: gValue = DAT_0049b88c

class Item {
  public:
    void Set(float);
};
class Thing {
  public:
    char pad[0x374c];
    Item* items[20];
    int count;
    void Run(float value);
};
void Thing::Run(float value) {
    (*(float*)&DAT_0049b88c) = value;
    for (int i = 0; i < count; ++i)
        items[i]->Set(value);
}