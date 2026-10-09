typedef unsigned int uint;
typedef unsigned char byte;
class Helper {
  public:
    void Run(uint value);
};
class Target {
  public:
    char pad0[4];
    void* first;
    Helper* middle;
    void* third;
    void Run(uint value);
};
void Target::Run(uint value) {
    middle->Run(value);
    *((byte*)first + 4) = (byte)((value >> 7) & 1);
    *((byte*)third + 4) = (byte)((value >> 8) & 1);
}
