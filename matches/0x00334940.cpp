// Same code shape as 0x0029c3b0 (propagated; names are from that function)
class Thing_334940 {
  public:
    virtual void F(int);
};
extern Thing_334940* gThing_334940;
void FUN_0029c3b0() {
    if (gThing_334940)
        gThing_334940->F(1);
    gThing_334940 = 0;
}