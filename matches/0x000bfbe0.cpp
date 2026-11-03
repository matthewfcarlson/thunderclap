#include "gen/owners.h"
class Manager_bfbe0 {
  public:
    void Start(const char*, int, int);
};
class Factory_bfbe0 {
  public:
    owners::Game_bfbe0* Create();
};
void owners::Game_bfbe0::FUN_000bfbe0(void* arg, float dt) {
    timer += dt;
    if (Check(0, 1))
        timer = 0.0f;
    if (timer >= 66.6f) {
        ((Manager_bfbe0*)((Factory_bfbe0*)arg)->Create())->Start("attract", 1000, 1);
        timer = 0.0f;
    }
}