// STATUS: equivalent (tools/equiv.py level 3: 2823 inputs, branch coverage 4/4)
// audio::SeqEventChannelSends::vfunc_1 @ 0x0024fae0
namespace audio { struct SeqEvent { virtual void vfunc_0(); virtual unsigned char vfunc_1(void **); }; struct SeqEventChannelSends : SeqEvent { unsigned char vfunc_1(void **); }; }
extern "C" unsigned char __cdecl FUN_00246f50(void *, const char *, ...);
unsigned char audio::SeqEventChannelSends::vfunc_1(void **output) {
    if (SeqEvent::vfunc_1(output) && FUN_00246f50(*output, "\n[\n")) {
        struct Output { char pad[0x24]; int depth; };
        ++((Output *)*output)->depth;
        FUN_00246f50(*output, "%s ", "mLayerName");
    }
    return 0;
}