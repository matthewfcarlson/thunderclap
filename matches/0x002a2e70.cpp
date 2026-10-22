class Light_2a2e70 {
  public:
    Light_2a2e70();
    virtual void f0();
};
struct Color {
    float x, y, z;
    Color() : x(0), y(0), z(1) {}
};
class DirectionalLight : public Light_2a2e70 {
  public:
    DirectionalLight();
    virtual void f0();
    char pad[0x50];
    int type;
    Color color;
};
DirectionalLight::DirectionalLight() {
    type = 2;
}