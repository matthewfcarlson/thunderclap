#include "decls/data/engine/pure3d.h"
// data: gCounter_327e00 = DAT_005555b8

class pddiShader_327e00 {
  public:
    pddiShader_327e00();
    virtual void f();
};
class pddiBaseShader_327e00 : public pddiShader_327e00 {
  public:
    pddiBaseShader_327e00();
    int pad[2];
    int id;
};
pddiBaseShader_327e00::pddiBaseShader_327e00() {
    id = (*(int*)&DAT_005555b8)++;
}
