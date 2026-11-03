#include "gen/owners.h"
extern "C" int __cdecl state(int);
extern "C" void __cdecl report(const char*);
class Factory {
  public:
    void* create(int, int);
};
class Owner_1c39e0 {
  public:
};
class Scene {
    char p[4];
    Owner_1c39e0* owner;
    char q[4];
    Factory* factory;

  public:
    void make(int, int);
};
void Scene::make(int a, int b) {
    int old = state(15);
    void* o = factory->create(a, b);
    if (o)
        ((owners::Bag_1c8810 *)owner)->FUN_001c8810((hulk_intptr)o);
    else
        report("Object creation failed!\n");
    state(old);
}