class Thing_29c3b0 {
  public:
    virtual void F(int);
};
extern Thing_29c3b0* gThing_29c3b0;
void FUN_0029c3b0() {
    if (gThing_29c3b0)
        gThing_29c3b0->F(1);
    gThing_29c3b0 = 0;
}