#include "gen/owners.h"
void owners::S_264510::FUN_00264510(unsigned n) {
    if (m0c && n) {
        if (!m0e) {
            A(n);
            return;
        }
        unsigned t = m2c + n;
        if (t <= m30) {
            m2c = t;
            m14 += n;
            return;
        }
        unsigned left = n;
        if (left > 0) {
            for (;;) {
                unsigned c = m2c;
                unsigned k = left;
                if (c + left > m30)
                    k = m30 - c;

                m2c += k;
                m14 += k;
                left -= k;
                if (left == 0)
                    break;
                B();
            }
        }
    }
}
