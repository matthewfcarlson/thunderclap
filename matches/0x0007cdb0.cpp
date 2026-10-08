class Obj { public: void Process(int); };
class Holder { public: char pad[0xc]; Obj *mObj; };
class Thing { public: char pad[0x3800]; int *mPtr; char pad2[0x24]; int mCount; Holder *mHolder; void Run(); void Cleanup(int); };
void Thing::Run() {
    while (mCount > 0) {
        int *p = mPtr;
        mHolder->mObj->Process(p[4]);
        if (mPtr != 0 && mPtr == p) Cleanup(0);
    }
}