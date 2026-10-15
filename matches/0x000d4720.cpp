class Obj {
  public:
    void Other(float, float, float, unsigned int, unsigned int);
    void Fn(float, float, float, float, float, float, float);
};
void Obj::Fn(float a, float b, float c, float d, float e, float f, float g) {
    unsigned int color = (int)d;
    color |= 0xffffff00;
    color <<= 8;
    color |= (int)e;
    color <<= 8;
    color |= (int)f;
    Other(a, b, c, color, *(volatile unsigned int*)&g);
}