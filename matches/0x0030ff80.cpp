#include "gen/physics.h"
struct Pose_30ff80 {
    void f650();
    void f4c0();
    void fa10(int);
};
class C_30ff80 {
    char pad0[8];
    int m8;
    physics::Pose* mc;

  public:
    void target(char b);
};
void C_30ff80::target(char b) {
    ((Pose_30ff80*)(mc))->f650();
    if (b) {
        ((Pose_30ff80*)(mc))->f4c0();
        return;
    }
    ((Pose_30ff80*)(mc))->fa10(m8);
}
