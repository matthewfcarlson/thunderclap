struct Node {
    int a;
    Node* next;
};

class SubObj_2728e0 {
  public:
    virtual void Fn0();
    virtual void Fn1();
};

class Container_2728e0 {
  public:
    char pad[0xc];
    SubObj_2728e0 mSub;
    char pad2[0x38 - 0xc - 4];
    Node* mHead;
    Node* mTail;
    void Add(Node* p);
};

void Container_2728e0::Add(Node* p) {
    mSub.Fn0();
    if (mHead == 0) {
        mHead = p;
    } else {
        mTail->next = p;
    }
    p->next = 0;
    mTail = p;
    mSub.Fn1();
}
