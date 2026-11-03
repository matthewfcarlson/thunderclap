// FUN_001c4580 @ 0x001c4580

// Moves toward the target; stops once the position has passed it.
#include "gen/owners.h"
void owners::Slider_1c4580::FUN_001c4580(float dt)
{
    position += dt * rate;
    float diff = position - target;
    float diffSign = diff < 0.0f ? -1.0f : (diff > 0.0f ? 1.0f : 0.0f);
    float rateSign = rate < 0.0f ? -1.0f : (rate > 0.0f ? 1.0f : 0.0f);
    if (diffSign == rateSign) {
        position = target;
        active = false;
        rate = 0.0f;
    }
}
