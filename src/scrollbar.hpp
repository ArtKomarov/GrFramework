#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include "windowmanager.hpp"
#include "button.hpp"
#include "slider.hpp"

class ScrollBar : public WindowManager {
    Slider slider_;
    Button but1_;
    Button but2_;
public:
    ScrollBar();
};

#endif // SCROLLBAR_HPP
