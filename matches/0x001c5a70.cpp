#include "gen/Render.h"
struct Object_nv_1c5a70 {
    void Update(int);
};
class Container {
  public:
    Render::Object* Find(int);
    void Remove(int);
    void Erase(void*, Render::Object*);
};
class Owner {
  public:
    char pad[8];
    Container items;
    void Act(int, int);
};
void Owner::Act(int key, int value) {
    Container* c = &items;
    Render::Object* n = c->Find(key);
    if (n) {
        c->Remove(key);
        ((Object_nv_1c5a70*)(n))->Update(value);
        c->Erase((char*)n + 8, n);
    }
}