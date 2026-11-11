// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00085d90..0x00088e60 (kind game, layer game, confidence high), dominant class CTimeManager
// (tree_prelude.h: not needed)


// 0x00088b80 FUN_00088b80 (163 B): matches/0x00088b80.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?f@Obj_88b80@fn_fc637429@@QAEXPAVCx@2@@Z
#include "gen/owners.h"
namespace fn_fc637429 {} using namespace fn_fc637429;
namespace fn_fc637429 {
class Ca {
  public:
    void Run();
};
class Cb {
  public:
    void Run();
};
class Cc {
  public:
    void Run();
};
class Cd {
  public:
    void Run();
};
class Ce {
  public:
    void Run();
};
class Cf {
  public:
    void Run();
};
class Cg {
  public:
    void Run();
};
class Ch {
  public:
    void Run();
};
class Ci {
  public:
    void Run();
};
class Cj {
  public:
    void Run();
};
class Ck {
  public:
    void Run();
};
class Cl {
  public:
    void Run();
};
class Cm {
  public:
    void Run();
};
class Cn {
  public:
    void Run();
    void Run2();
};
class Co {
  public:
    void Run();
};
class Cp {
  public:
    void Run(int);
};
class Cn2 {
  public:
    void Run2();
};
class Cx {
  public:
};
class Cq {
  public:
    void Use(int);
};
struct Obj_88b80 {
    char z[8];
    Ck* p08;
    Ce* p0c;
    Ci* p10;
    Cg* p14;
    Cj* p18;
    char g1c[4];
    Cf* p20;
    Ch* p24;
    Cc* p28;
    Ca* p2c;
    Cb* p30;
    char g34[4];
    Cm* p38;
    Cq* p3c;
    Cn* p40;
    Cl* p44;
    Co* p48;
    Cd* p4c;
    Cp* p50;
    void f(Cx*);
};
void Obj_88b80::f(Cx* x) {
    int q = ((int)((owners::C_862b0 *)x)->FUN_000862b0());
    p3c->Use(q);
    p2c->Run();
    p30->Run();
    p28->Run();
    p4c->Run();
    p0c->Run();
    p20->Run();
    p14->Run();
    p24->Run();
    p10->Run();
    p18->Run();
    p08->Run();
    p44->Run();
    p38->Run();
    p40->Run();
    p48->Run();
    p50->Run(1);
    p40->Run2();
}
} // namespace fn_fc637429

