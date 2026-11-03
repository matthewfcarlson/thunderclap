#include "gen/owners.h"
struct Temp_27a590 {
    char data[8];
    void Build(int);
    void Finish();
};
struct Item_27a590 {
    char data[8];
    void Copy(Temp_27a590*);
};
void owners::Obj_27a590::FUN_0027a590(hulk_intptr a, hulk_intptr b) {
    Temp_27a590 t;
    if (count < 20) {
        t.Build(((int)a));
        ((Item_27a590*)((char*)this + count * 8))->Copy(&t);
        t.Finish();
        values[count] = ((int)b);
        ++count;
    }
}