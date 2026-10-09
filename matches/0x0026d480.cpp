extern int gValue;
void Init();
class Allocator {
  public:
    int* Construct();
};
int* Allocator::Construct() {
    *(int*)this = 0x42b3fc;
    ((int*)this)[1] = 0x42afa8;
    ((int*)this)[2] = gValue;
    Init();
    ((int*)this)[1] = 0x42b3a4;
    ((int*)this)[3] = 0;
    Init();
    *(int*)this = 0x42b3b4;
    ((int*)this)[1] = 0x42b3ac;
    ((int*)this)[4] = 0;
    ((int*)this)[5] = 0;
    ((int*)this)[6] = 0;
    ((int*)this)[7] = 0;
    ((int*)this)[8] = 0;
    ((int*)this)[9] = 0;
    ((int*)this)[10] = 0;
    Init();
    return (int*)this;
}