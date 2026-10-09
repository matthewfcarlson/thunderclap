class LocatorLoader {
  public:
    int vptr;
    int a;
    int b;
    int c;
    int d;
    LocatorLoader();
};
LocatorLoader::LocatorLoader() {
    a = 0;
    b = 0x14000;
    c = 0;
    d = 0;
    vptr = 0x42ebb0;
}