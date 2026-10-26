#include "decls/data/game/unknown.h"

class Obj {
  public:
    virtual void AddRef();
    virtual void Release();
};
void* operator new(unsigned int) throw();
class Shader_85d30 : public Obj {
    char pad[28];

  public:
    Shader_85d30() throw();
};
void target() {
    Shader_85d30* p = new Shader_85d30;
    if (p)
        p->AddRef();
    if ((*(Obj**)&DAT_004dd6e4))
        (*(Obj**)&DAT_004dd6e4)->Release();
    (*(Obj**)&DAT_004dd6e4) = p;
}