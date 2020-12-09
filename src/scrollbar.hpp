#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include "windowmanager.hpp"
#include "button.hpp"
#include "slider.hpp"

namespace GrFramework {

class ScrollBar : public ElemManager {
    Slider slider_;
    Button but1_;
    Button but2_;
public:
    ScrollBar(double *sliderParams, double *butParams1, double *butParams2);
};

}

#endif // SCROLLBAR_HPP
