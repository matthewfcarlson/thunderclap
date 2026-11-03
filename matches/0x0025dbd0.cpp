#include "compat/ptr.h"
#include "gen/owners.h"
class Ref_25dbd0 {
  public:
    virtual void A();
    virtual void Release(int);
};
void owners::Owner_25dbd0::FUN_0025dbd0(int* p) {
    int* next = p + 1;
    int* prev = 0;
    int* cur = head;
    while (cur != next) {
        prev = cur;
        cur = (int*)*(hulk_intptr*)cur;
    }
    if (prev == 0) {
        head = (int*)*(hulk_intptr*)next;
    } else {
        *prev = *next;
    }
    if (*next == 0)
        tail = prev;
    if (p != 0)
        ((Ref_25dbd0*)p)->Release(1);
}