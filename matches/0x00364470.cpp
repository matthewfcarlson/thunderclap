class Thing {
  public:
    void go();
};
extern Thing globalThing;
void __cdecl FUN_00364470() {
    globalThing.go();
}