class Base { public: void Done(); };
class TypeA { public: void Done(); };
class TypeB { public: void Done(); };
class CCollisionTrack {
public:
    virtual void Dummy();
    char pad[0x14];
    char a18[0x34];
    char a4c[0xc];
    char a58[0x10];
    char a68[8];
    char a70[4];
    void Fini();
};
void CCollisionTrack::Fini() {
    *(int*)this = 0x3fa214;
    ((TypeA*)a70)->Done();
    ((TypeA*)a68)->Done();
    ((TypeB*)a58)->Done();
    ((TypeB*)a4c)->Done();
    ((TypeA*)a18)->Done();
    ((Base*)this)->Done();
}
