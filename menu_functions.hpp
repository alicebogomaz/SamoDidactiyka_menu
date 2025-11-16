#pragma once

#include "menu.hpp"

namespace ABogomaz {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);


    const MenuItem* study_summ(const MenuItem* current);
    const MenuItem* study_subtract(const MenuItem* current);
    const MenuItem* study_multiply(const MenuItem* current);
    const MenuItem* study_divide(const MenuItem* current);
    const MenuItem* study_go_back(const MenuItem* current);
}
