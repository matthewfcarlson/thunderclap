#include "gen/owners.h"
class Ret_2b3d0 {
  public:
    void D(int);
    void E();
    char pad[0x20a8];
    int m;
};
class Prov_2b3d0 {
  public:
};
class Sub_2b3d0 {
  public:
    char pad[0x44];
    Prov_2b3d0* prov;
    Ret_2b3d0* Get(int id) { return ((Ret_2b3d0 *)((owners::ThisWrap_00059c10 *)prov)->FUN_00059c10((void *)(hulk_uintptr)(int)id)); }
};
class Obj_2b3d0 {
  public:
    Sub_2b3d0* sub;
    int pad4[2];
    int count;
    int items[0x124 / 4 - 4];
    Ret_2b3d0* current;
    void removeAt(int, int);
    void run();
};
void Obj_2b3d0::run() {
    int i = count - 1;
    if (i >= 0) {
        int* p = &items[i];
        do {
            Prov_2b3d0* pr = sub->prov;
            Ret_2b3d0* r = ((Ret_2b3d0 *)((owners::ThisWrap_00059c10 *)pr)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (r && r != current) {
                ((owners::C_36d40 *)r)->FUN_00036d40(0);
                removeAt(i, 0);
            }
            --i;
            --p;
        } while (i >= 0);
    }
    if (current) {
        current->D(1);
        current->E();
        current->m = 0;
    }
}
