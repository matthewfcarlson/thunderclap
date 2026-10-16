#include "gen/fight.h"

typedef unsigned int u32_23b950;
struct DataReader_23b950 {
    char pad[8];
    struct Helper_23b950* member;
};
struct Helper_23b950 {
    u32_23b950 call(u32_23b950, u32_23b950, u32_23b950, u32_23b950);
};

int fight::StreamDataReader::vfunc_4(int __p0, int __p1) { u32_23b950 a = (u32_23b950)__p0; u32_23b950 b = (u32_23b950)__p1;

    (*(struct Helper_23b950 * *)&this->f_08)->call(a, b, 1, 1);
    return (int)(b);
}
