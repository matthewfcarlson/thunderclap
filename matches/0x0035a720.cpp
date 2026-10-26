#include "decls/data/engine/unknown.h"
// data: gCount_35a720 = DAT_0056f024, gItems_35a720 = DAT_0056f000

struct Item_35a720 {
    virtual void Run();
};
void __cdecl Target(Item_35a720* p) {
    ((Item_35a720**)&DAT_0056f000)[(*(int*)&DAT_0056f024)] = p;
    p->Run();
    ++(*(int*)&DAT_0056f024);
}