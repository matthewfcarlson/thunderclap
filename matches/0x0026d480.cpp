extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
extern "C" char DAT_0042b3ac[];
extern "C" char DAT_0042b3b4[];
extern "C" char DAT_0042b3fc[];
extern int gValue_26d480;
void Init();
class Allocator {
  public:
    int* Construct();
};
int* Allocator::Construct() {
    *(int*)this = ((int)DAT_0042b3fc);
    ((int*)this)[1] = ((int)DAT_0042afa8);
    ((int*)this)[2] = gValue_26d480;
    Init();
    ((int*)this)[1] = ((int)DAT_0042b3a4);
    ((int*)this)[3] = 0;
    Init();
    *(int*)this = ((int)DAT_0042b3b4);
    ((int*)this)[1] = ((int)DAT_0042b3ac);
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