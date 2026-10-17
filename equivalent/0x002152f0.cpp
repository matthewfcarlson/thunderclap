// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002152f0 @ 0x002152f0
extern "C" int __cdecl __setjmp3(void *environment, int count);
struct ExceptionFrame { ExceptionFrame *previous; char environment[64]; int result; volatile int extra; };
struct Context { char padding[0x50]; ExceptionFrame *frame; };
typedef void (__cdecl *Callback)(Context *, void *);
int __cdecl FUN_002152f0(Context *context, Callback callback, void *argument)
{
    ExceptionFrame frame;
    frame.previous = context->frame;
    context->frame = &frame;
    frame.result = 0;
    frame.extra = 0;
    if (__setjmp3(frame.environment, 0) == 0)
        callback(context, argument);
    context->frame = frame.previous;
    return frame.result + frame.extra;
}
