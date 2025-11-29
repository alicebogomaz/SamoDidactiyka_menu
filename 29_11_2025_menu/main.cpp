#include "menu.hpp"
#include "menu_items.hpp"
#include "menu_func.hpp"

int main() {
    const ABogomaz::MenuItem* current = &ABogomaz::MAIN;
    do {
        current = current->func(current);
    } while(true);

    return 0;
}
