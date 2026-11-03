#include "gen/owners.h"
class Helper_24380 {
  public:
};
class Obj_24380 {
  public:
    virtual void v0();
    char pad[8];
    int count;
    int items[1];
    bool find(int);
};
bool Obj_24380::find(int value) {
    int i = 0;
    if (count > 0) {
        do {
            Helper_24380* h = *(Helper_24380**)((char*)*(int**)this + 0x44);
            int result = ((int)((owners::ThisWrap_00059c10 *)h)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
            if (result != 0 && result == value) {
                ((owners::ItemList_24320 *)this)->FUN_00024320(i);
                return true;
            }
            ++i;
        } while (i < count);
    }
    return false;
}
