class Owner_27cf40 {
  public:
    char pad[8];
    int a;
    int b;
    Owner_27cf40* GetThing();
    void DoThing(int, int, int);
    void Run(int x);
};
void Owner_27cf40::Run(int x) {
    Owner_27cf40* p = GetThing();
    if (p)
        p->DoThing(a, b, x);
}