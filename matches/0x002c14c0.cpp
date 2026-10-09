extern int gVtable;
class LightGroupLoader {
  public:
    int vf;
    int a;
    int b;
    int c;
    int d;
    LightGroupLoader();
};
LightGroupLoader::LightGroupLoader() {
    a = 0;
    b = 0x2380;
    c = 0;
    d = 0;
    vf = (int)&gVtable;
}