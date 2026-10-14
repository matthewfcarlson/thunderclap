class Thing_31e1f0 {
  public:
    virtual void Call(int, int);
};
extern Thing_31e1f0* gThing_31e1f0;
void thunk(int a, int b) {
    if (gThing_31e1f0)
        gThing_31e1f0->Call(a, b);
}