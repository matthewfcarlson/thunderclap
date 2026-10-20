#include "decls/data/engine/audio.h"
#include "decls/data/engine/pure3d.h"

extern "C" char DAT_00415244[];
extern "C" char DAT_00415247[];
extern "C" char DAT_00445053[];
extern "C" char DAT_0046494c[];
extern "C" char DAT_00495053[];
extern int vt1_2d4040;
class Src_2d4040 {
  public:
    void* Find(unsigned a, unsigned b) throw();
};
class D {
  public:
    void* vptr;
    void* v[18];
    D(Src_2d4040* s) throw();
};
D::D(Src_2d4040* s) throw() {
    v[0] = 0;
    vptr = &vt1_2d4040;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
    v[5] = 0;
    v[6] = 0;
    v[7] = 0;
    v[8] = 0;
    v[9] = 0;
    v[10] = 0;
    v[11] = 0;
    v[12] = 0;
    v[13] = 0;
    v[14] = 0;
    v[15] = 0;
    v[16] = 0;
    v[17] = 0;
    if (s) {
        v[1] = s->Find(((int)((char*)0x544152)), 0x31544c46);
        v[2] = s->Find(((int)0x46494c), 0x31544c46);
        v[3] = s->Find(0x5646494c, 0x31544c46);
        v[4] = s->Find(((int)0x445053), 0x31544c46);
        v[5] = s->Find(0x56445053, 0x31544c46);
        v[6] = s->Find(0x5a4953, 0x31544c46);
        v[7] = s->Find(0x565a4953, 0x31544c46);
        v[8] = s->Find(((int)0x495053), 0x31544c46);
        v[9] = s->Find(0x56495053, 0x31544c46);
        v[10] = s->Find(((int)((char*)0x544757)), 0x31544c46);
        v[11] = s->Find(0x56544757, 0x31544c46);
        v[12] = s->Find(((int)0x415247), 0x31544c46);
        v[13] = s->Find(((int)0x415244), 0x31544c46);
        v[14] = s->Find(((int)((char*)0x524c43)), ((int)((char*)0x524c43)));
        v[15] = s->Find(0x56524c43, ((int)((char*)0x544e49)));
        v[16] = s->Find(((int)((char*)0x504c41)), ((int)((char*)0x544e49)));
        v[17] = s->Find(0x56504c41, ((int)((char*)0x544e49)));
    }
}
