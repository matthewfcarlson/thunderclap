class Ref { public: virtual void Release(int); };
class Owner { char pad[8]; Ref* mRef; public: void Clear(); };
void Owner::Clear() { if (mRef) { mRef->Release(1); mRef = 0; } }