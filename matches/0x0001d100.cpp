class Ref { public: virtual void A(); virtual void B(); };
extern int actionVftable;
extern int keyVftable;
class Action { public: Action(); virtual void A(); virtual void B(); char pad[0x18]; Ref *mRef; int mValue; int m9; int m10; int m11; };
class KeyPoseAction : public Action { public: KeyPoseAction(int, Ref *); virtual void A(); };
KeyPoseAction::KeyPoseAction(int value, Ref *ref) : Action() {
 *(int *)this=(int)&actionVftable;
 mRef=0;
 if(ref) ref->A();
 if(mRef) mRef->B();
 mRef=ref; mValue=value; m9=0; m10=0; m11=0;
 *(int *)this=(int)&keyVftable;
}