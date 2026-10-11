extern "C" char DAT_003faf2c[];
struct Small {
    ~Small();
    char p[12];
};
struct Big {
    ~Big();
    char p[16];
};
struct Other {
    ~Other();
    char p[4];
};
struct Base {
    virtual ~Base();
};
struct CWeaponCollisionTrack : Base {
    char pad[0x28];
    Small c;
    Big b;
    Other a;
    virtual void Kill();
};
void CWeaponCollisionTrack::Kill() {
    *(int*)this = ((int)DAT_003faf2c);
    a.~Other();
    b.~Big();
    c.~Small();
    this->Base::~Base();
}
