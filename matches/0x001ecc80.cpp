class Part_1ecc80 {
  public:
    int Check();
};
class Obj_1ecc80 {
  public:
    char pad[0xec];
    Part_1ecc80* component;
};
class Owner_1ecc80 {
  public:
    char pad[0x11c];
    Part_1ecc80* component;
};
class Thing_1ecc80 {
  public:
    char pad[0x1c];
    void Play(Obj_1ecc80*, const char*, float, int);
    void Fn(Owner_1ecc80*, Obj_1ecc80*, Obj_1ecc80*, int);
};
void Thing_1ecc80::Fn(Owner_1ecc80* a, Obj_1ecc80* b, Obj_1ecc80* c, int d) {
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