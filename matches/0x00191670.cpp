#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int RTTI1_191670, RTTI2;
class Created_191670 {
  public:
    int init(hulkfight::motion::TankLocomotionTrack*, int);
};
extern int typecheck(void*, int, int*, int*, int);
extern Created_191670* alloc(int);

hulk_intptr hulkfight::motion::TankLocomotionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (typecheck((void*)c, 0, &RTTI1_191670, &RTTI2, 0)) {
        Created_191670* p = alloc(0xa4);
        if (p)
            return p->init(this, c);
    }
    return 0;
}
