#pragma once

#include "menu.hpp"

namespace ABogomaz {
    const MenuItem* show_main(const MenuItem* current);
    const MenuItem* show_poets(const MenuItem* current);
    const MenuItem* show_poems(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);

    const MenuItem* pushkin(const MenuItem* current);
    const MenuItem* lermontov(const MenuItem* current);
    const MenuItem* krylov(const MenuItem* current);

    const MenuItem* dubrovsky(const MenuItem* current);
    const MenuItem* onegin(const MenuItem* current);
    const MenuItem* winter(const MenuItem* current);
}
