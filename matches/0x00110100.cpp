#include "decls/data/game/global.h"

namespace fight {
class ParamEnumConstList {
  public:
    char pad[16];
    const char** list;
    int count;
    const char* vfunc_6(int unused, int index);
};
} // namespace fight
const char* fight::ParamEnumConstList::vfunc_6(int unused, int index) {
    if (index >= 0 && index < count)
        return list[index];
    return ((char*)&DAT_003f335c);
}