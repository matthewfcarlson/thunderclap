struct Viewport_321520 {
    int x;
    int y;
    int width;
    int height;
};
void __stdcall GetViewport(Viewport_321520*);
void __stdcall SetViewport(Viewport_321520*);
class Thing_321520 {
    char pad[0x16c];

  public:
    Viewport_321520 vp;
    void f(float, float, float, float);
};
void Thing_321520::f(float a, float b, float c, float d) {
    GetViewport(&vp);
    vp.x = (int)a;
    vp.y = (int)b;
    vp.width = (int)c;
    vp.height = (int)d;
    SetViewport(&vp);
}
