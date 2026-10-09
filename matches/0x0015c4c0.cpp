struct Data {
    char pad[0x14];
    int a;
    int b;
    unsigned char c;
};
class LocomotionStrafe4Action {
  public:
    char pad[0x44];
    Data* mData;
    void vfunc_8(int* p2, int* p3, unsigned char* p4);
};
void LocomotionStrafe4Action::vfunc_8(int* p2, int* p3, unsigned char* p4) {
    *p2 = mData->a;
    *p3 = mData->b;
    *p4 = mData->c;
}