#include "gen/owners.h"
class Slot_23a660 {
  public:
};
int owners::Owner_23a660::FUN_0023a660(void* arg) {
    int i = count;
    int r = -1;
    if (i < 0x200) {
        Slot_23a660* s = (Slot_23a660*)((char*)this + (i * 3) * 8 + 0x130);
        ((owners::Target_27b040 *)s)->FUN_0027b040((hulk_uintptr)arg);
        *(int*)((char*)this + (i * 3 + 0x27) * 8) = 0;
        count++;
        r = i;
    }
    return r;
}