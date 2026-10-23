// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 2/2)
// FUN_002152f0 @ 0x002152f0
extern "C" int __cdecl __setjmp3(void *environment, int count);
struct ExceptionFrame { ExceptionFrame *previous; char environment[64]; int result;
#if defined(_MSC_VER) && !defined(__clang__)
    volatile int extra; // MSVC 7.1 puts the frame 4 bytes lower without it (the stored address is compared)
#endif
};
#if defined(_MSC_VER) && !defined(__clang__)
#define FRAME_EXTRA(f) f.extra
#define FRAME_INIT(f) f.extra = 0
#else
#define FRAME_EXTRA(f) 0
#define FRAME_INIT(f)
#endif
struct Context { char padding[0x50]; ExceptionFrame *frame; };
typedef void (__cdecl *Callback)(Context *, void *);
int __cdecl FUN_002152f0(Context *context, Callback callback, void *argument)
{
    ExceptionFrame frame;
    frame.previous = context->frame;
    context->frame = &frame;
    frame.result = 0;
    FRAME_INIT(frame);
    if (__setjmp3(frame.environment, 0) == 0)
        callback(context, argument);
    context->frame = frame.previous;
    return frame.result + FRAME_EXTRA(frame);
}
