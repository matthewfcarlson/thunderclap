typedef unsigned __int64 U64_256c20;
extern U64_256c20 __cdecl Hash(const char*, int, int);
extern const char Sequence[];
extern const char Data_Sequence[];
class Base_256c20 {
  public:
    Base_256c20(const U64_256c20&, const U64_256c20&, int, int, int);
    virtual void f();
};
namespace audio {
class SequenceType : public Base_256c20 {
  public:
    SequenceType();
    virtual void f();
};
} // namespace audio
audio::SequenceType::SequenceType()
    : Base_256c20(Hash(Sequence, 0, 0), Hash(Data_Sequence, 0, 0), 0x1000001, 0x58, 8) {}