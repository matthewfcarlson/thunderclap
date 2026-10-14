class Obj_1b6d70 {
  public:
    int a;
    float b;
    int c;
    float d;
    int e;
    float f;
    void Tick(float);
};
void Obj_1b6d70::Tick(float dt) {
    if (a != 0) {
        b -= dt;
        if (b <= 0.0f)
            a = 0;
    }
    if (c != 0) {
        d -= dt;
        if (d <= 0.0f)
            c = 0;
    }
    if (e != 0) {
        f -= dt;
        if (f <= 0.0f)
            e = 0;
    }
}