#include "gen/fight.h"

struct ParamValue_169ca0 {
    char pad[0x10];
};

struct ParamValueEnum_169ca0 : ParamValue_169ca0 {};

template <> int fight::ParamEnumConstList<hulkfight::motion::RageModeStateCondition>::vfunc_7(int arg) {
    return this->f_14;
}
