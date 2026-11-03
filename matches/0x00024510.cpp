// Same code shape as 0x000244e0 (propagated; names are from that function)
#include "gen/owners.h"
class Helper_24510 {
  public:
};
class Owner_24510 {
  public:
    char pad[0x44];
    Helper_24510* mHelper;
};
class Outer_24510 {
  public:
    Owner_24510* mOwner;
    int pad[2];
    int count;
    int items[1];
    void run();
};
void Outer_24510::run() {
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
