typedef unsigned __int64 U64;
extern U64 __cdecl Hash(const char*, int, int);
extern const char Sequence[];
extern const char Data_Sequence[];
class Base {
  public:
    Base(const U64&, const U64&, int, int, int);
    virtual void f();
};
namespace audio {
class SequenceType : public Base {
  public:
    SequenceType();
    virtual void f();
};
} // namespace audio
audio::SequenceType::SequenceType()
    : Base(Hash(Sequence, 0, 0), Hash(Data_Sequence, 0, 0), 0x1000001, 0x58, 8) {}