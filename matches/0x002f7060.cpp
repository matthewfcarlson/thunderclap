extern int vftable;
class PhysicsObjectLoader {
  public:
    int vptr;
    int a;
    int b;
    int c;
    int d;
    PhysicsObjectLoader();
};
PhysicsObjectLoader::PhysicsObjectLoader() {
    a = 0;
    b = 0x7011000;
    c = 0;
    d = 0;
    vptr = (int)&vftable;
}
