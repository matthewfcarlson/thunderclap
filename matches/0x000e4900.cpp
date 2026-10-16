extern int gOne, gTwo;
extern void __cdecl Process(int, int, int*, int*, int);
class FEContainer {
  public:
#define V(n) virtual void vfunc_##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) virtual int vfunc_39(void*);
    virtual void vfunc_40();
    virtual void vfunc_41(void*);
};
void FEContainer::vfunc_41(void* p) {
    Process(vfunc_39(p), 0, &gOne, &gTwo, 0);
}
