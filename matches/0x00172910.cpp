namespace hulkfight {
namespace motion {
class Q_172910 {
  public:
    void* f1();
};
class R_172910 {
  public:
    void* f2();
};
class S_172910 {
  public:
    void* f3(int);
};
class VisibilityAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int, int);
    char pad[0x1c - 4];
    void* mA;
    void* mB;
};
bool VisibilityAction::vfunc_3(int, int) {
    if (mB) {
        void* x = ((Q_172910*)mB)->f1();
        if (x) {
            void* y = ((R_172910*)x)->f2();
            if (y) {
                void* z = ((S_172910*)y)->f3(1);
                *(unsigned char*)((char*)z + 0xa8) = *(((unsigned char*)mA) + 0x10);
            }
        }
    }
    return false;
}
} // namespace motion
} // namespace hulkfight
