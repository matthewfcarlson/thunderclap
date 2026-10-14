// STATUS: equivalent (tools/equiv.py level 3: 1600 inputs, branch coverage 14/14)
// audio::SeqEventPlayTrack::vfunc_1 @ 0x00251610
struct Stream { char pad[0x24]; unsigned int depth; };
struct Context { Stream* stream; };
bool __cdecl FUN_00246f50(Stream*, const char*);
bool __cdecl FUN_0024eb60(Context*, const char*, unsigned int*);
bool __cdecl FUN_00250ef0(Context*, const char*, unsigned int*);
bool __cdecl FUN_0024e600(Context*, const char*, char*);
namespace audio {
struct SeqEvent {
 virtual void vfunc_0();
 virtual bool vfunc_1(Context*);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 unsigned int field4;
};
struct SeqEventPlayTrack : SeqEvent {
 unsigned int fadeTimeMs;
 unsigned int delayTimeMs;
 unsigned int targetResume;
 char seqTrackNameBuf[1];
 virtual bool vfunc_1(Context*);
};
bool SeqEventPlayTrack::vfunc_1(Context* context) {
 if (!SeqEvent::vfunc_1(context)) return false;
 if (!FUN_00246f50(context->stream, "\n[\n")) return false;
 ++context->stream->depth;
 if (!FUN_0024eb60(context, "mFadeTimeMs", &fadeTimeMs)) return false;
 if (!FUN_0024eb60(context, "mDelayTimeMs", &delayTimeMs)) return false;
 if (!FUN_00250ef0(context, "mTargetResume", &targetResume)) return false;
 if (!FUN_0024e600(context, "mSeqTrackNameBuf", seqTrackNameBuf)) return false;
 --context->stream->depth;
 if (!FUN_00246f50(context->stream, "]\n")) return false;
 return true;
}
}
