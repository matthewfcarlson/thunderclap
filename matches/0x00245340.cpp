class Clip {
public:
    virtual void f();
    char pad[0x24];
    void* m28;
    void Done();
    void Finish();
};
void Release(void*);
void Clip::Done() {
    *(void**)this = (void*)0x42918c;
    if (m28) Release(m28);
    Finish();
}
