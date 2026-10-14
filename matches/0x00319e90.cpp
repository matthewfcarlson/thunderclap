// cl-flags: /O2 /GR /GX

class Data_319e90 {
  public:
    void Init(void* src);
};

struct Element_319e90 {
    void* header;
    Data_319e90 data;
};

class Container_319e90 {
    char _pad0[4];

  public:
    Element_319e90* mCurrent;
    Element_319e90* mEnd;

  private:
    char _padC[0xA0 - 0xC];
    int mState;

  public:
    void Add(void* param2, void* param3);
};

void Container_319e90::Add(void* param2, void* param3) {
    if (mState != 2) {
        char buffer[0x64];
        *(void**)buffer = param2;
        Data_319e90* temp = (Data_319e90*)(buffer + 4);
        temp->Init(param3);

        if (mCurrent < mEnd) {
            Element_319e90* oldCurrent = mCurrent;
            mCurrent = (Element_319e90*)((char*)mCurrent + 0x64);
            if (oldCurrent) {
                oldCurrent->header = *(void**)buffer;
                oldCurrent->data.Init(temp);
            }
        }
    }
}