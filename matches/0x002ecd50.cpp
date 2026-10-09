namespace physics {
extern const float one;
class SimLength {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(float);
    virtual void vfunc_2();
    virtual void vfunc_3();
};
void SimLength::vfunc_1(float value) {
    *(float*)((char*)this + 8) = value;
    *(float*)((char*)this + 4) = one * value;
}
} // namespace physics