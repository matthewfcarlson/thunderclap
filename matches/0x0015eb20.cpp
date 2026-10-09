class Thing { public: virtual void A(); virtual void B(); };
class Base { public: virtual void X(); Base(); };
class ClimbLocomotionAction : public Base { public: virtual void A(); char pad[0x18]; Thing* mThing; int m20; int m24; ClimbLocomotionAction(Thing*); };
ClimbLocomotionAction::ClimbLocomotionAction(Thing* p) { mThing=0; m20=0; m24=0; if(p) p->A(); if(mThing) mThing->B(); mThing=p; }
