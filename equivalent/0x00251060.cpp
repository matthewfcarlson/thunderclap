// STATUS: equivalent (tools/equiv.py level 3: 1600 inputs, branch coverage 14/14)
// audio::SeqEventStopTrack::vfunc_1 @ 0x00251060
struct Stream { char pad[0x24]; unsigned int depth; };
char __cdecl FUN_00246f50(Stream*, const char*);
char __cdecl FUN_0024eb60(Stream**, const char*, unsigned int*);
struct NameBuffer { char data[12]; };
char __cdecl FUN_0024e600(Stream**, const char*, NameBuffer*);
char __cdecl FUN_00250ef0(Stream**, const char*, unsigned char*);
namespace audio {
struct SeqEvent {
 virtual void vfunc_0();
 virtual int vfunc_1(Stream**);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 unsigned int field4;
};
struct SeqEventStopTrack : SeqEvent {
 virtual void vfunc_0();
 virtual int vfunc_1(Stream**);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 unsigned int fadeTimeMs;
 unsigned int delayTimeMs;
 NameBuffer trackName;
 unsigned char stopOtherTracks;
};
int SeqEventStopTrack::vfunc_1(Stream** stream) {
 if (!(unsigned char)SeqEvent::vfunc_1(stream)) return 0;
 if (!FUN_00246f50(*stream,"\n[\n")) return 0;
 ++(*stream)->depth;
 if (!FUN_0024eb60(stream,"mFadeTimeMs",&fadeTimeMs)) return 0;
 if (!FUN_0024eb60(stream,"mDelayTimeMs",&delayTimeMs)) return 0;
 if (!FUN_0024e600(stream,"mSeqTrackNameBuf",&trackName)) return 0;
 if (!FUN_00250ef0(stream,"mStopOtherTracks",&stopOtherTracks)) return 0;
 --(*stream)->depth;
 if (!FUN_00246f50(*stream,"]\n")) return 0;
 return 1;
}
}
