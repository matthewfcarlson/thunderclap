#include "gen/owners.h"
class Obj {
  public:
    virtual void Go();
};
class Source {
  public:
};
class Target {
  public:
    char pad[4];
    Obj* obj;
    void Fn(Source* src);
};
void Target::Fn(Source* src) {
    if (src) {
        obj = ((Obj *)((owners::C_ae640 *)src)->FUN_000ae640(0));
        obj->Go();
    }
}