#include "gen/owners.h"
int owners::Search_294ed0::FUN_00294ed0(unsigned short key) {
    int low = 0;
    int high = count - 1;
    if (high >= 0) {
        do {
            int mid = (high + low) >> 1;
            unsigned short value = values[mid];
            if (key == value)
                return mid;
            if (key < value)
                high = mid - 1;
            else
                low = mid + 1;
        } while (low <= high);
    }
    return -1;
}