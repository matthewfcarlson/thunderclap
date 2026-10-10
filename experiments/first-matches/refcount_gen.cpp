// refcount.cpp rewritten against the generated headers (include/gen/). Verify with:
//   build/venv/bin/python tools/compare.py experiments/first-matches/refcount_gen.cpp 0x18b40
#include <gen/pure3d.h>

namespace pure3d {

// FUNCTION: 0x00018b40 (pure3d::NonCopyable::vfunc_1) -- Release
void NonCopyable::vfunc_1() {
    if (--f_04 < 1) {
        delete this;
    }
}

}
