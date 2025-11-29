#include <iostream>
#include <cstdlib>

#include "menu.hpp"
#include "menu_func.hpp"

namespace {
    const ABogomaz::MenuItem* show_menu(const ABogomaz::MenuItem* current) {
        for (int i = 1; i < current->children_count; i++) {
            std::cout << current->children[i]->title << std::endl;
        }

        std::cout << current->children[0]->title << std::endl;
        std::cout << "Читаем: ";

        int user_input;
        std::cin >> user_input;
        std::cout << std::endl;

        return current->children[user_input];
    };
}

const ABogomaz::MenuItem* ABogomaz::show_main(const ABogomaz::MenuItem* current) {
    std::cout << "Главное меню: " << std::endl;
    return show_menu(current);
};

const ABogomaz::MenuItem* ABogomaz::show_poets(const ABogomaz::MenuItem* current) {
    std::cout << "Второй уровень меню: " << std::endl;
    return show_menu(current);
};

const ABogomaz::MenuItem* ABogomaz::show_poems(const ABogomaz::MenuItem* current) {
    std::cout << "Третий уровень Пушкина: " << std::endl;
    return show_menu(current);
};

const ABogomaz::MenuItem* ABogomaz::exit(const ABogomaz::MenuItem* current) {
    std::exit(0);
};

const ABogomaz::MenuItem* ABogomaz::go_back(const ABogomaz::MenuItem* current) {
    return current->parent->parent;
};

const ABogomaz::MenuItem* ABogomaz::pushkin(const ABogomaz::MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
};

const ABogomaz::MenuItem* ABogomaz::lermontov(const ABogomaz::MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
};


const ABogomaz::MenuItem* ABogomaz::krylov(const ABogomaz::MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
};


const ABogomaz::MenuItem* ABogomaz::dubrovsky(const ABogomaz::MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
};


const ABogomaz::MenuItem* ABogomaz::onegin(const ABogomaz::MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
};


const ABogomaz::MenuItem* ABogomaz::winter(const ABogomaz::MenuItem* current) {
    std::cout << current->title << std::endl;
    return current->parent;
};
