// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 14/14)
// FUN_0027cc60 @ 0x0027cc60
// FUN_0027cc60 @ 0x0027cc60: notifies every listener of each timeline event whose time lies in [from, to)
struct Dispatcher;

struct Event {
    char pad00[0xc];
    float time;
};

struct Timeline {
    char pad00[0x34];
    int count;
    Event *events;
};

class Listener {
public:
    virtual void OnEvent(Event *event, Dispatcher *dispatcher);
};

struct Dispatcher {
    char pad00[0x90];
    int listenerCount;
    Listener *listeners[16];
    void FUN_0027cc60(Timeline *timeline, float from, float to);
};

void Dispatcher::FUN_0027cc60(Timeline *timeline, float from, float to)
{
    if (listenerCount <= 0)
        return;
    for (int i = 0; i < timeline->count; i++) {
        Event *event = &timeline->events[i];
        if (event->time >= from && event->time < to) {
            for (int k = 0; k < listenerCount; k++)
                listeners[k]->OnEvent(event, this);
        }
    }
}
