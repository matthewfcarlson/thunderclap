extern "C" char DAT_003faf2c[];
struct Small_62150 {
    ~Small_62150();
    char p[12];
};
struct Big_62150 {
    ~Big_62150();
    char p[16];
};
struct Other_62150 {
    ~Other_62150();
    char p[4];
};
struct Base {
    virtual ~Base();
};
struct CWeaponCollisionTrack : Base {
    char pad[0x28];
    Small_62150 c;
    Big_62150 b;
    Other_62150 a;
    virtual void Kill();
};
void CWeaponCollisionTrack::Kill() {
    *(int*)this = ((int)DAT_003faf2c);
    a.~Other_62150();
    b.~Big_62150();
    c.~Small_62150();
    this->Base::~Base();
}
