#include "gen/owners.h"
class Helper_236790 {
    char pad[0x18];

  public:
    Helper_236790(void*);
    int Run(int, int);
};
int owners::Target_236790::FUN_00236790(int a, int b) {
    Helper_236790 h((char*)this + 0x14);
    return h.Run(a, b);
}