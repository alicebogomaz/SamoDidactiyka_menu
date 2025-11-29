#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"
#include "menu.hpp"

const ABogomaz::MenuItem* ABogomaz::show_menu(const MenuItem* current) {

    std::cout << current->greeting << std::endl;

    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }

    std::cout << current->children[0]->title << std::endl;
    std::cout << "СамоДидактийка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;
    return current->children[user_input];
}

const ABogomaz::MenuItem* ABogomaz::exit(const MenuItem* current) {
    std::exit(0);
}
const ABogomaz::MenuItem* ABogomaz::go_back(const MenuItem* current) {
    return current->parent->parent;
}

const ABogomaz::MenuItem* ABogomaz::algebra_summ(const MenuItem* current) {
   return current->parent;
}
const ABogomaz::MenuItem* ABogomaz::algebra_subtract(const MenuItem* current) {
    return current->parent;
}
const ABogomaz::MenuItem* ABogomaz::algebra_multiply(const MenuItem* current) {
    return current->parent;
}
const ABogomaz::MenuItem* ABogomaz::algebra_divide(const MenuItem* current) {
    return current->parent;
}

const ABogomaz::MenuItem* ABogomaz::math_diff(const MenuItem* current) {
    return current->parent;
}
const ABogomaz::MenuItem* ABogomaz::math_integ(const MenuItem* current) {

    return current->parent;
}


