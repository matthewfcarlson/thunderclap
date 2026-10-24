#include "gen/pure3d.h"

class ParticleGenerator_2d2510 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual float vfunc_8(int);
    virtual void a9();
    virtual void a10();
    virtual void a11();
};
extern const float zero_2d2510;

hulk_freg pure3d::ParticlePointGenerator::vfunc_8(int n) {
    --n;
    if (n != 0) {
        --n;
        if (n != 0) {
            --n;
            if (n != 0)
                return zero_2d2510;
            return this->f_4c;
        }
        return this->f_48;
    }
    return this->f_44;
}
