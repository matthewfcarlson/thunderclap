void* operator new(unsigned int n);

class Base_299c50 {
  public:
    Base_299c50() { mA = 0; }
    virtual void f0();
    int mA;
};

class ActivePrimitiveList_299c50 : public Base_299c50 {
  public:
    ActivePrimitiveList_299c50();
    virtual void f0();
    char* mBuf1;
    char* mEnd1;
    char pad10[4];
    char* mBuf2;
    char* mEnd2;
    char pad1c[4];
    char mFlag;
    char pad21[3];
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
};

void Base_299c50::f0() {}

ActivePrimitiveList_299c50::ActivePrimitiveList_299c50() {
    char* p = (char*)operator new(0x20);
    mBuf1 = p;
    if (p) {
        mEnd1 = p + 0x20;
    } else {
        mBuf1 = 0;
        mEnd1 = 0;
    }
    char* q = (char*)operator new(0x20);
    mBuf2 = q;
    if (q) {
        mEnd2 = q + 0x20;
    } else {
        mBuf2 = 0;
        mEnd2 = 0;
    }
    mFlag = 0;
    m24 = 0;
    m28 = 0;
    m30 = 0;
    m34 = 0;
    m3c = 0;
    m40 = 0;
    for (unsigned int i = 0; i < 0x20; i++) {
        mBuf1[i] = 0;
        mBuf2[i] = 0;
    }
}

void ActivePrimitiveList_299c50::f0() {}
