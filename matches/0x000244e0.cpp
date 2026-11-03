#include "gen/owners.h"
class Helper_244e0 {
  public:
};
class Owner_244e0 {
  public:
    char pad[0x44];
    Helper_244e0* mHelper;
};
class Outer_244e0 {
  public:
    Owner_244e0* mOwner;
    int pad[2];
    int count;
    int items[1];
    void run();
};
void Outer_244e0::run() {
    int i = 0;
    if (count > 0) {
        int* p = items;
        do {
            ((owners::ThisWrap_00059c10 *)(mOwner->mHelper))->FUN_00059c10((void *)(hulk_uintptr)(int)(*p));
            ++i;
            ++p;
        } while (i < count);
    }
}
