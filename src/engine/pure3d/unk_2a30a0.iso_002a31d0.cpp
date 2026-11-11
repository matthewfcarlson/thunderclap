// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a30a0..0x002a34c0 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x002a31d0 FUN_002a31d0 (120 B): matches/0x002a31d0.cpp [isolated: macros; on include/gen/ and not mergeable]
// sym: ?FUN_002a31d0@Target_2a31d0@owners@@QAEXXZ
#include "gen/owners.h"
class Manager {
  public:
#define V(n) virtual int v##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
                V(53) V(54) virtual int v55();
    virtual int v56(int, int, int, int);
    V(57) V(58) V(59) virtual int v60(int);
    V(61) virtual int v62(int);
    V(63) virtual int v64(int);
    V(65) virtual int v66(int);
    V(67) V(68) V(69) virtual int v70(int);
    V(71) virtual int v72(int);
};
extern Manager* hulk_at_0052c2a8;
void owners::Target_2a31d0::FUN_002a31d0() {
    Manager* m = hulk_at_0052c2a8;
    m->v62(0);
    value = hulk_at_0052c2a8->v55();
    m->v60(5);
    m->v64(1);
    m->v66(1);
    m->v72(-1);
    m->v70(-1);
    m->v56(0, 0, 0, 0);
}

