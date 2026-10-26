#include "decls/data/engine/unknown.h"
// data: gCount_35a740 = DAT_0056f024, gList_35a740 = DAT_0056f000

struct Obj_35a740 {
    virtual void f0();
    virtual void f1();
};
void RemoveObj(Obj_35a740* o) {
    int i = 0;
    if ((*(int*)&DAT_0056f024) > 0) {
        do {
            if (((Obj_35a740**)&DAT_0056f000)[i] == o) {
                ((Obj_35a740**)&DAT_0056f000)[i]->f1();
                int last = (*(int*)&DAT_0056f024) - 1;
                ((Obj_35a740**)&DAT_0056f000)[i] = 0;
                (*(int*)&DAT_0056f024) = last;
                if (i != last) {
                    ((Obj_35a740**)&DAT_0056f000)[i] = ((Obj_35a740**)&DAT_0056f000)[last];
                    ((Obj_35a740**)&DAT_0056f000)[last] = 0;
                }
                return;
            }
            i++;
        } while (i < (*(int*)&DAT_0056f024));
    }
}
