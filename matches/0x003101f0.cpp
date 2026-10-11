extern "C" char DAT_0043217c[];
class PhysicsObject {
  public:
    PhysicsObject* Init();
};
void InitBase();
PhysicsObject* PhysicsObject::Init() {
    InitBase();
    *(unsigned int*)this = ((int)DAT_0043217c);
    *(unsigned int*)((char*)this + 0x1fc) = 0;
    *(unsigned int*)((char*)this + 0x24) = 1;
    return this;
}