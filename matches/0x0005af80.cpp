class CGrappleSequenceTrack {
  public:
    char pad[0x1c];
    void Target();
};
class A {
  public:
    void InitA();
};
class B {
  public:
    void InitB();
};
class C {
  public:
    void Finish();
};
void CGrappleSequenceTrack::Target() {
    *(void**)this = (void*)0x003f9a2c;
    ((A*)((char*)this + 0x1c))->InitA();
    ((B*)((char*)this + 0x0c))->InitB();
    ((C*)this)->Finish();
}