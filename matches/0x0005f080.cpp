#include "gen/fight.h"
extern void* v[];
struct Base_5f080 {  };
class ParamName_5f080 {
  public:
    void* vptr;
    char pad[12];
    int m10;
    ParamName_5f080(int a, int b) throw();
};
ParamName_5f080::ParamName_5f080(int a, int b) throw() {
    ((fight::ParamValueName *)(((Base_5f080*)this)))->FUN_00234a90((const char *)(hulk_uintptr)(int)a);
    vptr = v;
    m10 = b;
}
