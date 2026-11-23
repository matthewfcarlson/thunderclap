// Colour grade (wlook1, docs/look.md "Colour grade"): what the HDR pass's tone map needs from the grade pass.
#pragma once

namespace rm {

// the u_rmGrade[4] constants for this frame (fs_rm_grade.sh), null when Grade is Original
const float* gradeConstants();
// the tone map graded this frame's scene (the log's count)
void gradeDoneInToneMap();

} // namespace rm
