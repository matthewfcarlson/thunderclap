#include "gen/owners.h"
class X_307ef0 {
  public:
    int n;
    int cap;
    char* buf;
    char* next();
};
char* X_307ef0::next() {
    if (n >= cap)
        ((owners::Buffer_3048a0 *)this)->FUN_003048a0(cap * 2);
    ++n;
    return buf + n - 1;
}