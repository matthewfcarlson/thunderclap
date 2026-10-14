extern const float k = 0.0174532924f;
class C {
  public:
    char Pad[20];
    float f;
    char Fn(float x);
};
char C::Fn(float x) {
    f = x * k;
    return 1;
}