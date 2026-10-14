class Thing_29bb0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_29bb0 {
  public:
    char pad[0x344];
    int key;
    Thing_29bb0* current;
    int value;
    void Set(int k, Thing_29bb0* t, int v);
};
void Owner_29bb0::Set(int k, Thing_29bb0* t, int v) {
    if (k == key) {
        if (t)
            t->A();
        if (current)
            current->B();
        current = t;
        value = v;
    }
}