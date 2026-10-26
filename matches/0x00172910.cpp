#include "compat/ptr.h"
#include "gen/hulkfight.h"

namespace hulkfight {
namespace motion {
class Q_172910 {
  public:
    void* f1();
};
class R_172910 {
  public:
    void* f2();
};
class S_172910 {
  public:
    void* f3(int);
};

} // namespace motion
} // namespace hulkfight
bool hulkfight::motion::VisibilityAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if ((*(void * *)&this->f_20)) {
        void* x = ((Q_172910*)(*(void * *)&this->f_20))->f1();
        if (x) {
            void* y = ((R_172910*)x)->f2();
            if (y) {
                void* z = ((S_172910*)y)->f3(1);
                *(unsigned char*)((char*)z + 0xa8) = *(((unsigned char*)(*(void * *)&this->f_1c)) + 0x10);
            }
        }
    }
    return false;
}
