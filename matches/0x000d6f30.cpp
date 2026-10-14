class Thing_d6f30 {
  public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void act(void*);
};
class Owner_d6f30 {
  public:
    char pad[4];
    Thing_d6f30* first;
    Thing_d6f30* second;
    void Run(int a, void* b);
};
void Owner_d6f30::Run(int a, void* b) {
    second->act(b);
    first->act(b);
}