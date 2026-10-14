extern const float k_68140 = 0.0174532924f;
class C_68140 {
  public:
    char Pad[20];
    float f;
    char Fn(float x);
};
char C_68140::Fn(float x) {
    f = x * k_68140;
    return 1;
}