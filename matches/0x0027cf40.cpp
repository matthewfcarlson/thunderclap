class Owner {
  public:
    char pad[8];
    int a;
    int b;
    Owner* GetThing();
    void DoThing(int, int, int);
    void Run(int x);
};
void Owner::Run(int x) {
    Owner* p = GetThing();
    if (p)
        p->DoThing(a, b, x);
}