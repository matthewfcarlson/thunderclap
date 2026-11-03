#include "gen/owners.h"
class Obj_290340 {
  public:
    char pad[8];
    int field;
    void Init();
    void Configure(void*);
    Obj_290340* Run(void*);
};
Obj_290340* Obj_290340::Run(void* arg) {
    Init();
    field = 0;
    Configure(arg);
    ((owners::Obj_28fe80 *)this)->FUN_0028fe80((const char *)(hulk_uintptr)(int)(*(int*)((char*)arg + 8)));
    return this;
}