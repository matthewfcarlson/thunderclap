#include "decls/data/engine/core.h"
// data: g_data_275e50 = DAT_0052a1e8
// core::File's IMutable slots enter / leave the "File" pool's critical section (0x0052a1e8)
namespace core {
class File {
  public:
    void vfunc_0_adj4();
};
} // namespace core
extern "C" void FUN_0026d850(void*);
void core::File::vfunc_0_adj4() {
    FUN_0026d850(((char*)&DAT_0052a1e8));
}
