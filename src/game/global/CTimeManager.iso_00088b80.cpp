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
    void Run_001cd400();
};
class Cb {
  public:
    void Run_001cbf90();
};
class Cc {
  public:
    void Run_001fd730();
};
class Cd {
  public:
    void Run_0007d5b0();
};
class Ce {
  public:
    void Run_001e11d0();
};
class Cf {
  public:
    void Run_0002a890();
};
class Cg {
  public:
    void Run_001b6a40();
};
class Ch {
  public:
    void Run_00201de0();
};
class Ci {
  public:
    void Run_001b4a50();
};
class Cj {
  public:
    void Run_00106400();
};
class Ck {
  public:
    void Run_0009a0e0();
};
class Cl {
  public:
    void Run_00059d30();
};
class Cm {
  public:
    void Run_001f6c90();
};
class Cn {
  public:
    void Run_001bc510();
    void Run2_001bc830();
};
class Co {
  public:
    void Run_001fac60();
};
class Cp {
  public:
    void Run_001bf860(int);
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
    void Use_000d6f10(int);
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
    p3c->Use_000d6f10(q);
    p2c->Run_001cd400();
    p30->Run_001cbf90();
    p28->Run_001fd730();
    p4c->Run_0007d5b0();
    p0c->Run_001e11d0();
    p20->Run_0002a890();
    p14->Run_001b6a40();
    p24->Run_00201de0();
    p10->Run_001b4a50();
    p18->Run_00106400();
    p08->Run_0009a0e0();
    p44->Run_00059d30();
    p38->Run_001f6c90();
    p40->Run_001bc510();
    p48->Run_001fac60();
    p50->Run_001bf860(1);
    p40->Run2_001bc830();
}
} // namespace fn_fc637429

