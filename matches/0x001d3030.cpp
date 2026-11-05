#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" void FUN_002133d0(void*, int);
extern "C" void FUN_00213600(void*, int);
extern "C" int FUN_00213190(void*, int);
extern "C" void FUN_00212d80(void*, int);

class Obj_1d3030 {
  public:
    char pad[8];
    void* ptr;
    char Check(const char*, int, int);
    hulk_intptr Run(const char*, hulk_intptr);
};

hulk_intptr Obj_1d3030::Run(const char* a, hulk_intptr b) {
    int result = 0;
    if (Check(DAT_003f6378, 1, 1)) {
        if (Check(a, 0, 1)) {
            if (Check(DAT_00422618, 0, 1)) {
                FUN_002133d0(ptr, b);
                FUN_00213600(ptr, -2);
                result = FUN_00213190(ptr, -1);
            }
        }
    }
    FUN_00212d80(ptr, 0);
    return result;
}
