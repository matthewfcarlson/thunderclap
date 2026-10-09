typedef unsigned char u8;
struct Sub { void Init(); };
class CUnlockable { public: virtual void v(); char pad4[4]; u8 member8; char pad9[7]; int member10; int member14; int member18; CUnlockable(); };
CUnlockable::CUnlockable() { member8 = 1; ((Sub*)((char*)this + 0x10))->Init(); member18 = 0; }