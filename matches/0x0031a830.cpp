#include "decls/data/engine/unknown.h"

extern "C" {
extern float c;
extern float d;
}
class Obj_31a830 {
  public:
    float v[25];
    Obj_31a830();
};
Obj_31a830::Obj_31a830() {
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 0.0f;
    v[4] = 0.0f;
    v[5] = 0.0f;
    v[6] = 0.0f;
    v[7] = 0.0f;
    v[8] = 0.0f;
    v[9] = 0.0f;
    v[10] = 0.0f;
    v[11] = 0.0f;
    v[12] = 0.0f;
    v[13] = 0.0f;
    v[14] = 0.0f;
    v[15] = 0.0f;
    v[16] = 1.0f;
    v[17] = 0.0f;
    v[18] = 0.0f;
    v[19] = (*(float*)&DAT_004d34e0);
    v[20] = (*(float*)&DAT_004d34e4);
    v[21] = c;
    v[22] = d * c;
    v[23] = DAT_004d34f0 * c;
}