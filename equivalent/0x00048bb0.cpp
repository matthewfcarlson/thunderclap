// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CCollisionHitLocationCondition::vfunc_7 @ 0x00048bb0
struct Target { char pad[0x74]; int value; };
struct Ctx { virtual void s0(); virtual void s1(); virtual void s2(); virtual Target* GetTarget(); };
class CCollisionHitLocationCondition {
public:
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual bool vfunc_7(Ctx* ctx);
 char pad[8];
 unsigned op;
 int threshold;
};
bool CCollisionHitLocationCondition::vfunc_7(Ctx* ctx) {
 Target* t = ctx->GetTarget();
 if (t) {
  int v = t->value;
  switch (op) {
  case 0: return v < threshold;
  case 1: return v <= threshold;
  case 2: return v == threshold;
  case 3: return v != threshold;
  case 4: return v >= threshold;
  case 5: return v > threshold;
  }
 }
 return false;
}
