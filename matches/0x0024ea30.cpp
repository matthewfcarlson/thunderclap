class SeqActionChannelSendVolumes { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void vfunc_6(int); char pad[8]; int state; };
void SeqActionChannelSendVolumes::vfunc_6(int) {
 int i = state;
 --i;
 if (i != 0) {
  i -= 3;
  if (i != 0) {
   --i;
   if (i == 0) state = 0;
   return;
  }
 }
 state = 2;
}