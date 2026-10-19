extern "C" char DAT_0043217c[];
class PhysicsObject {
  public:
    PhysicsObject* Init();
};
struct ThisCall_002f5480 {
    void InitBase();
};
PhysicsObject* PhysicsObject::Init() {
    ((ThisCall_002f5480*)(this))->InitBase();
    *(unsigned int*)this = ((int)DAT_0043217c);
    *(unsigned int*)((char*)this + 0x1fc) = 0;
    *(unsigned int*)((char*)this + 0x24) = 1;
    return this;
}