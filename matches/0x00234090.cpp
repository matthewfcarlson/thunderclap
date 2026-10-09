class Ref { public: virtual void A(); virtual void Release(); };
class Owner { public: Ref *mRef; bool Clear(Ref *); };
bool Owner::Clear(Ref *unused) { if (mRef) { mRef->Release(); mRef = 0; } return true; }