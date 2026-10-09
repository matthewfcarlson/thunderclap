class ProceduralVertexAnimController {
  public:
    char pad[0x40];
    int a;
    int b;
    void h1();
    void h2();
    void vfunc_7();
};
void ProceduralVertexAnimController::vfunc_7() {
    if (a)
        h1();
    else if (b)
        h2();
}