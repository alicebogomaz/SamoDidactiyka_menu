#pragma once

#include "menu.hpp"

namespace ABogomaz {
    // Renders the current menu, prompts the user, and returns the next node to display.
    const MenuItem* show_menu(const MenuItem* current);

    // Terminates the program immediately.
    const MenuItem* exit(const MenuItem* current);

    // Lesson handlers: show content, wait for Enter, then return to parent.
    const MenuItem* study_summ(const MenuItem* current);
    const MenuItem* study_subtract(const MenuItem* current);
    const MenuItem* study_multiply(const MenuItem* current);
    const MenuItem* study_divide(const MenuItem* current);

    // Navigation helper for explicit "Back" entries.
    const MenuItem* study_go_back(const MenuItem* current);

    // Build the full menu tree (root shared_ptr).
    std::shared_ptr<MenuItem> create_menu();
}
