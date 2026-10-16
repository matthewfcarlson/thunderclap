class Thing {
  public:
    void Act(int);
};
class Owner {
  public:
    char pad[0x8c];
    Thing* thing;
    void Run(int);
};
void Owner::Run(int x) {
    if (!thing)
        return;
    return thing->Act(x);
}