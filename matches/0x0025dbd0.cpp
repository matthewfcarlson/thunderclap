#include "compat/ptr.h"
class Ref_25dbd0 {
  public:
    virtual void A();
    virtual void Release(int);
};
class Owner_25dbd0 {
  public:
    char pad[0x4c];
    int* head;
    int* tail;
    void Remove(int*);
};
void Owner_25dbd0::Remove(int* p) {
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