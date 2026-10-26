#include "decls/data/engine/unknown.h"
// data: count = DAT_0056f024, current = DAT_004dbf6c, items = DAT_0056f000

class Item {
  public:
    virtual void A();
    virtual void B();
    virtual void Set(int);
    virtual int Get();
};
void FUN_0035a6c0(int v) {
    DAT_004dbf6c = v;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (*(int*)&DAT_0056f024); j++) {
            if (((Item**)&DAT_0056f000)[j]->Get() == i)
                ((Item**)&DAT_0056f000)[j]->Set(DAT_004dbf6c);
        }
    }
}