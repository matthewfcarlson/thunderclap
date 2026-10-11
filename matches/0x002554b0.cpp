class SeqAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void*);
    int pad4;
    char* mOwner;
    int mState;
    int mHandle;
};
extern int __cdecl Find(int, int);
extern void __cdecl Stop(int);
extern void __cdecl Start(int, int, int, bool, int);
struct Obj {
    char pad[0x3c];
    int value;
};
class SeqActionCrossFade : public SeqAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void*);
};
void SeqActionCrossFade::v6(void* p) {
    switch (mState) {
    case 1: {
        int value = ((Obj*)p)->value;
        int h = Find(value, mHandle);
        if (h) {
            if (h > 1 && h <= 4)
                mState = 2;
        } else {
            bool flag = (mOwner[0x18] == 0);
            int value2 = ((Obj*)p)->value;
            Start(value2, mHandle, 0, flag, 1);
        }
        break;
    }
    case 3: {
        int value = ((Obj*)p)->value;
        int h = Find(value, mHandle);
        if (!h) {
            mState = h;
            Stop(mHandle);
            mHandle = 0;
        }
        break;
    }
    }
}