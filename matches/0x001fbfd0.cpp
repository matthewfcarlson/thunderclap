#include "gen/owners.h"
extern "C" void __cdecl Format(char*, unsigned int, const char*, void*);
class Inner_1fbfd0 {
  public:
};
class Obj_1fbfd0 {
  public:
    char pad[8];
    Inner_1fbfd0 inner;
    char pad2[0x10];
    void Run(void*);
};
void Obj_1fbfd0::Run(void* arg) {
    Format((char*)this + 0x20, 0x20, "%s", arg);
    ((owners::Target_27b040 *)&inner)->FUN_0027b040((hulk_uintptr)arg);
}