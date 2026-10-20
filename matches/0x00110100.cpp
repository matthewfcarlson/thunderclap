#include "gen/fight.h"

#include "decls/data/game/global.h"

namespace fight {
} // namespace fight
template <> void* fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition>::vfunc_6(int unused, int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(const char ** *)&this->f_10)[index]);
    return (void*)(((char*)&DAT_003f335c));
}
