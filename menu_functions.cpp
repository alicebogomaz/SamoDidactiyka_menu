#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"

const ABogomaz::MenuItem* ABogomaz::exit(const MenuItem* current) {
    std::exit(0);
}
const ABogomaz::MenuItem* ABogomaz::show_menu(const MenuItem* current) {
    std::cout << "привет-привет! саморазвитие is the real punk rock! :)" << std::endl;

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

const ABogomaz::MenuItem* ABogomaz::study_summ(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const ABogomaz::MenuItem* ABogomaz::study_subtract(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const ABogomaz::MenuItem* ABogomaz::study_multiply(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const ABogomaz::MenuItem* ABogomaz::study_divide(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    return current->parent;
}

const ABogomaz::MenuItem* ABogomaz::study_go_back(const MenuItem* current) {
    //TODO
    return current->parent->parent;
}
