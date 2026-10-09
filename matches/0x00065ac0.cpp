class Clock { public: float Get(); };
class Obj {
public:
    char pad0[4];
    Clock* mClock;
    char pad8[0x35c];
    float mDeadline;
    char pad2[4];
    unsigned char mActive;
    void Target();
};
void Obj::Target() {
    if (mActive) {
        float now = mClock->Get();
        if (mDeadline <= now) {
            mActive = 0;
            mDeadline = 0.0f;
        }
    }
}