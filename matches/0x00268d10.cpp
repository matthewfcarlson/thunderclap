#include "gen/core.h"

typedef unsigned int u32_268d10;
extern float __stdcall GetPointX(u32_268d10);
namespace core {

} // namespace core
void core::ControllerInputPointXBox::vfunc_12(int __p0) { u32_268d10 arg = (u32_268d10)__p0;

    this->f_08 = GetPointX(arg);
}
