// STATUS: equivalent (tools/equiv.py level 3: 2397 inputs, branch coverage 20/20)
// FUN_001ae150 @ 0x001ae150
// FUN_001ae150 @ 0x001ae150: removes the first occurrence of a value from a ring buffer, rotating the older entries
#include "compat/ptr.h"
class Ring_1ae150 {
public:
    char pad00[0x18];
    int *head;
    int *tail;
    int *begin;
    int *end;
    void FUN_001ae150(int value);
};

void Ring_1ae150::FUN_001ae150(int value)
{
    hulk_intptr count;
    if (head > tail)
        count = (tail - begin) + (end - head);
    else
        count = tail - head;

    for (int i = 0; i < count; i++) {
        int v = *head;
        if (tail >= end)
            tail = head;
        head++;
        if (head == end)
            head = begin;
        if (value == v)
            return;
        if (tail < end) {
            if (tail)
                *tail = v;
            tail++;
            if (tail == end)
                tail = begin;
            if (head == tail)
                tail += end - begin;
        }
    }
}
