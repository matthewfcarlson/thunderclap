#include "gen/pure3d.h"

class Decoder_28d510 {
  public:
    void* Decode(void*);
};
struct Q_28d510 {
    unsigned int a, b, c, d;
};

template <> void pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_3(int index, void* __p1, void* __p2) { float * time = (float *)__p1; void * out = (void *)__p2;

    short v = (*(short * *)&this->f_14)[index];
    *time = (float)(int)v;
    char local[16];
    Q_28d510* p = (Q_28d510*)((Decoder_28d510*)((*(char * *)&this->f_18) + index * 6))->Decode(local);
    *(Q_28d510*)out = *p;
}
