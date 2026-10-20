class StreamStringReader_23a520 {
  public:
    virtual void A();
    virtual void B();
    virtual ~StreamStringReader_23a520() throw();
};
class StreamStringReader : public StreamStringReader_23a520 {
  public:
    char pad[8];
    StreamStringReader_23a520* m;
    virtual void A();
    virtual void B();
    ~StreamStringReader() throw();
};
void StreamStringReader_23a520::A() {}
void StreamStringReader_23a520::B() {}
StreamStringReader_23a520::~StreamStringReader_23a520() throw() {}
void StreamStringReader::A() {}
void StreamStringReader::B() {}
StreamStringReader::~StreamStringReader() throw() {
    m->B();
}
