class Thing {
  public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void act(void*);
};
class Owner {
  public:
    char pad[4];
    Thing* first;
    Thing* second;
    void Run(int a, void* b);
};
void Owner::Run(int a, void* b) {
    second->act(b);
    first->act(b);
}