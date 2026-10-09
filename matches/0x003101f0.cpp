class PhysicsObject { public: PhysicsObject* Init(); };
void InitBase();
PhysicsObject* PhysicsObject::Init() {
    InitBase();
    *(unsigned int*)this = 0x43217c;
    *(unsigned int*)((char*)this + 0x1fc) = 0;
    *(unsigned int*)((char*)this + 0x24) = 1;
    return this;
}