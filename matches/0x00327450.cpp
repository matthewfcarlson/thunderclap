#include "gen/pure3d.h"

namespace pure3d {
class pddiPrimBufferStream_327450 {
  public:
    virtual void vfunc_0(int, int, int);
};
struct d3dPrimBufferStream_nv_327450 {
    void Advance();
};

} // namespace pure3d
void pure3d::d3dPrimBufferStream::vfunc_0(int a, int b, int c) {
    (*(int * *)&this->f_24)[0] = a;
    (*(int * *)&this->f_24)[1] = b;
    (*(int * *)&this->f_24)[2] = c;
    ((d3dPrimBufferStream_nv_327450*)this)->Advance();
}
