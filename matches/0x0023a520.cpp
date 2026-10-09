class IRefCount {
  public:
    virtual void A();
    virtual void B();
    virtual ~IRefCount() throw();
};
class StreamStringReader : public IRefCount {
  public:
    char pad[8];
    IRefCount* m;
    virtual void A();
    virtual void B();
    ~StreamStringReader() throw();
};
void IRefCount::A() {}
void IRefCount::B() {}
IRefCount::~IRefCount() throw() {}
void StreamStringReader::A() {}
void StreamStringReader::B() {}
StreamStringReader::~StreamStringReader() throw() {
    m->B();
}
