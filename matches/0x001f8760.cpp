class Child_1f8760 {
  public:
};
class Thing_1f8760 {
  public:
    void Do(Child_1f8760*);
};
class Owner_1f8760 {
  public:
    char pad[0x448];
    Child_1f8760* child;
    Thing_1f8760* Get();
    void Set(Child_1f8760*);
};
void Owner_1f8760::Set(Child_1f8760* arg) {
    Thing_1f8760* t = Get();
    Child_1f8760* old = child;
    t->Do(old);
    child = arg;
}
