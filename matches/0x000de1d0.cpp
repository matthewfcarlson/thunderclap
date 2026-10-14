typedef float(__cdecl* RandomFn)();
extern RandomFn gRandom;
class Obj_de1d0 {
  public:
    char pad[0x2c];
    float second;
    char pad2[4];
    float first;
    void Update();
};
void Obj_de1d0::Update() {
    first += gRandom();
    second += gRandom();
}