// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024f1c0 @ 0x0024f1c0
int __cdecl FUN_002673a0(const char *, int);
namespace audio { struct Base { Base(); virtual void method(); }; struct SeqEventChannelSendVolumes : Base { int unused; int volumes[16]; int count; int sound; SeqEventChannelSendVolumes(); virtual void method(); }; }
audio::SeqEventChannelSendVolumes::SeqEventChannelSendVolumes() : Base() { sound = FUN_002673a0("stitched", 0); count = 100; for (int i=0;i<16;++i) volumes[i]=0; }