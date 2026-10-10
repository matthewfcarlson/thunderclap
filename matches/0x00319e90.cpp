// cl-flags: /O2 /GR /GX

class Data {
  public:
    void Init(void* src);
};

struct Element {
    void* header;
    Data data;
};

class Container {
    char _pad0[4];

  public:
    Element* mCurrent;
    Element* mEnd;

  private:
    char _padC[0xA0 - 0xC];
    int mState;

  public:
    void Add(void* param2, void* param3);
};

void Container::Add(void* param2, void* param3) {
    if (mState != 2) {
        char buffer[0x64];
        *(void**)buffer = param2;
        Data* temp = (Data*)(buffer + 4);
        temp->Init(param3);

        if (mCurrent < mEnd) {
            Element* oldCurrent = mCurrent;
            mCurrent = (Element*)((char*)mCurrent + 0x64);
            if (oldCurrent) {
                oldCurrent->header = *(void**)buffer;
                oldCurrent->data.Init(temp);
            }
        }
    }
}