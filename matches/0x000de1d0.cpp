typedef float (__cdecl *RandomFn)();
extern RandomFn gRandom;
class Obj { public: char pad[0x2c]; float second; char pad2[4]; float first; void Update(); };
void Obj::Update() { first += gRandom(); second += gRandom(); }