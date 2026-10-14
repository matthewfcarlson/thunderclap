extern "C" int __cdecl state(int);
extern "C" void __cdecl report(const char*);
class Factory {
  public:
    void* create(int, int);
};
class Owner_1c39e0 {
  public:
    void attach(void*);
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
        owner->attach(o);
    else
        report("Object creation failed!\n");
    state(old);
}