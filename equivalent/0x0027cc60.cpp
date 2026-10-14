// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 14/14)
// FUN_0027cc60 @ 0x0027cc60
// FUN_0027cc60 @ 0x0027cc60: notifies every listener of each timeline event whose time lies in [from, to)
struct Dispatcher_27cc60;

struct Event_27cc60 {
    char pad00[0xc];
    float time;
};

struct Timeline_27cc60 {
    char pad00[0x34];
    int count;
    Event_27cc60 *events;
};

class Listener_27cc60 {
public:
    virtual void OnEvent(Event_27cc60 *event, Dispatcher_27cc60 *dispatcher);
};

struct Dispatcher_27cc60 {
    char pad00[0x90];
    int listenerCount;
    Listener_27cc60 *listeners[16];
    void FUN_0027cc60(Timeline_27cc60 *timeline, float from, float to);
};

void Dispatcher_27cc60::FUN_0027cc60(Timeline_27cc60 *timeline, float from, float to)
{
    if (listenerCount <= 0)
        return;
    for (int i = 0; i < timeline->count; i++) {
        Event_27cc60 *event = &timeline->events[i];
        if (event->time >= from && event->time < to) {
            for (int k = 0; k < listenerCount; k++)
                listeners[k]->OnEvent(event, this);
        }
    }
}
