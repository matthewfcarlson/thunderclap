class Helper_102b60 {
  public:
    float f(int, int);
};
class CMoveAgent {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual float d(int, int);
};
extern volatile const float gZero_102b60;
float CMoveAgent::d(int x, int y) {
    ((Helper_102b60*)this)->f(x, y);
    float z = gZero_102b60;
    *(int*)((char*)this + 8) = 0;
    return z;
}