class Thing {
  public:
    ~Thing() throw();
};
extern Thing gThing;
void FUN_00364660() {
    gThing.~Thing();
}
