#include "gen/owners.h"
class Worker_24800 {
  public:
};

struct Container_24800 {
    char pad[0x44];
    Worker_24800* worker;
};

class Owner_24800 {
  public:
    Container_24800* mCont; // 0x00
    int f4;           // 0x04
    int f8;           // 0x08
    int count;        // 0x0c
    int arr[69];      // 0x10 .. 0x123
    int cmpVal;       // 0x124

    int func();
};

int Owner_24800::func() {
    int sum = 0;
    int i = 0;
    if (count > 0) {
        int* p = arr;
        do {
            Worker_24800* w = mCont->worker;
            int r = ((int)((owners::ThisWrap_00059c10 *)w)->FUN_00059c10((void *)(hulk_uintptr)(int)(*p)));
            if (r != 0 && r != cmpVal)
                ++sum;
            ++i;
            ++p;
        } while (i < count);
    }
    return sum;
}
