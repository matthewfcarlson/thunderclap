class Part {
  public:
    int Check();
};
class Obj {
  public:
    char pad[0xec];
    Part* component;
};
class Owner {
  public:
    char pad[0x11c];
    Part* component;
};
class Thing {
  public:
    char pad[0x1c];
    void Play(Obj*, const char*, float, int);
    void Fn(Owner*, Obj*, Obj*, int);
};
void Thing::Fn(Owner* a, Obj* b, Obj* c, int d) {
    if (!a)
        return;
    if (!a->component)
        return;
    if (!b)
        return;
    if (!b->component)
        return;
    if (!b->component->Check())
        return;
    if (!c)
        return;
    if (!c->component)
        return;
    if (!c->component->Check())
        return;
    Play(c, "impact_big", 100.0f, 0);
    Play(b, "impact_big", 100.0f, 0);
}