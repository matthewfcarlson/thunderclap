class Big { public: void Init(); };
class Small { public: void Init(); };
class Base { public: void Init(); };
class PhysicsObject {
public:
    void* vt;
    char pad[0x168-4];
    void Finish();
    void Setup();
};
void PhysicsObject::Setup() {
    vt = (void*)0x4315dc;
    ((Big*)((char*)this + 0x168))->Init();
    ((Small*)((char*)this + 0x114))->Init();
    ((Small*)((char*)this + 0xf8))->Init();
    ((Small*)((char*)this + 0xdc))->Init();
    ((Base*)((char*)this + 0x30))->Init();
    Finish();
}
