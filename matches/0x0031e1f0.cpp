class Thing {
  public:
    virtual void Call(int, int);
};
extern Thing* gThing;
void thunk(int a, int b) {
    if (gThing)
        gThing->Call(a, b);
}