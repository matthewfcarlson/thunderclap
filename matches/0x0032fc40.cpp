#include "gen/pure3d.h"
class Ref_32fc40 {
  public:
    virtual void A();
    virtual void Release();
};
extern int toonVftable;
class d3dToon2VertexShader_32fc40 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[0x7c];
    Ref_32fc40* m80;
    Ref_32fc40* m84;
    Ref_32fc40* m88;
    void Reset();
};
struct d3dToon2VertexShader_nv_32fc40 {
    void Go();
};
void d3dToon2VertexShader_32fc40::Reset() {
    *(int*)this = (int)&toonVftable;
    if (m88)
        m88->Release();
    if (m80)
        m80->Release();
    if (m84)
        m84->Release();
    ((d3dToon2VertexShader_nv_32fc40*)(((pure3d::d3dToon2VertexShader*)this)))->Go();
}
