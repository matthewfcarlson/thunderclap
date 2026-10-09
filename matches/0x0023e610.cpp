class Ref { public: virtual void Add(); virtual void Release(); };
class Parent { public: void Init(); };
extern int StopVtable;
class StopAction : public Parent { public: char pad[0x1c]; Ref *mRef; int mValue; int mArg; Ref *mOther; StopAction(Ref*, int, int, Ref*); };
StopAction::StopAction(Ref *a, int b, int c, Ref *d) { Init(); *(int*)this=(int)&StopVtable; mArg=c; mOther=0; mRef=a; a->Add(); mValue=b; if(d)d->Add(); if(mOther)mOther->Release(); mOther=d; }