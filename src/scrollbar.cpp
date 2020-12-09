#include "scrollbar.hpp"

namespace GrFramework {

ScrollBar::ScrollBar(double* sliderParams, double *butParams1, double *butParams2) :
    slider_(sliderParams[0], sliderParams[1], sliderParams[2], sliderParams[3]),
    but1_(&slider_, butParams1[0], butParams1[1], butParams1[2], butParams1[3]),
    but2_(&slider_, butParams2[0], butParams2[1], butParams2[2], butParams2[3]) {

}

}
