class Obj {
  public:
    virtual void A();
};
namespace content {
class LoadObject {
  public:
    virtual void f0();
    virtual void f1();
    int mRef;
    LoadObject() : mRef(0) {}
};
} // namespace content
namespace fight {
class StringReader : public content::LoadObject {
  public:
    virtual void f2();
    int mType;
    StringReader(int b) : mType(b) {}
};
class StreamStringReader : public StringReader {
  public:
    Obj* mStream;
    bool mDone;
    bool mErr;
    virtual void f2();
    StreamStringReader(Obj*, int);
};
StreamStringReader::StreamStringReader(Obj* s, int b) : StringReader(b) {
    mDone = false;
    mErr = false;
    mStream = s;
    s->A();
}
} // namespace fight
