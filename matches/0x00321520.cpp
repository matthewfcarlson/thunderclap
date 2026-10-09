struct Viewport {
    int x;
    int y;
    int width;
    int height;
};
void __stdcall GetViewport(Viewport*);
void __stdcall SetViewport(Viewport*);
class Thing {
    char pad[0x16c];

  public:
    Viewport vp;
    void f(float, float, float, float);
};
void Thing::f(float a, float b, float c, float d) {
    GetViewport(&vp);
    vp.x = (int)a;
    vp.y = (int)b;
    vp.width = (int)c;
    vp.height = (int)d;
    SetViewport(&vp);
}
