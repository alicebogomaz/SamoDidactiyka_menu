#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main() {
    // Set locale so console can display non-ASCII text if needed.
    std::setlocale(LC_ALL, "");

    // Build the menu tree (root node).
    auto menu = ABogomaz::create_menu();
    // Keep a raw pointer to the current menu node we are visiting.
    const ABogomaz::MenuItem* current = menu.get();

    // Infinite loop: each node knows which function should handle it.
    // The handler returns the next node we should show.
    do {
        current = current->func(current);
    } while (true);

    return 0; // Never reached because we exit via the menu.
}
