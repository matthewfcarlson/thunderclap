typedef unsigned int uint_d7030;
typedef unsigned char byte;
class Helper_d7030 {
  public:
    void Run(uint_d7030 value);
};
class Target_d7030 {
  public:
    char pad0[4];
    void* first;
    Helper_d7030* middle;
    void* third;
    void Run(uint_d7030 value);
};
void Target_d7030::Run(uint_d7030 value) {
    middle->Run(value);
    *((byte*)first + 4) = (byte)((value >> 7) & 1);
    *((byte*)third + 4) = (byte)((value >> 8) & 1);
}
