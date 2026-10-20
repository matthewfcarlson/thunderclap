#include "compat/ptr.h"
class Queue_25dba0 {
  public:
    char pad[0x4c];
    int* head;
    int* tail;
    void Add(int* item);
};

void Queue_25dba0::Add(int* item) {
    int* node = item + 1;
    *node = 0;
    if (tail == 0) {
        head = node;
        tail = node;
    } else {
        *tail = (hulk_intptr)node;
        tail = node;
    }
}
