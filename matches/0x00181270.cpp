struct BallAndChainShootTrack {
  virtual void vfunc_0();
  virtual void vfunc_1();
  virtual void vfunc_2();
  virtual void vfunc_3();
  virtual void vfunc_4();
  virtual void vfunc_5();
  virtual void vfunc_6();
  virtual float GetLength();
  virtual void vfunc_8();
  virtual void vfunc_9();
  virtual void vfunc_10();
  char pad[8];
  float mStart;
  float mEnd;
};

float BallAndChainShootTrack::GetLength() {
  return mEnd - mStart;
}