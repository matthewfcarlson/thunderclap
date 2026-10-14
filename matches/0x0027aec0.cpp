extern "C" char DAT_0042c140[];
class Ref_27aec0 {
  public:
    virtual void f0();
    virtual void f1();
};
void thunk(void*);
class RDLReader {
  public:
    void* vptr;
    Ref_27aec0* member;
    void* data;
    void Close();
};
void RDLReader::Close() {
    vptr = (void*)((int)DAT_0042c140);
    if (member) {
        member->f1();
        member = 0;
        if (data)
            thunk(data);
    }
}