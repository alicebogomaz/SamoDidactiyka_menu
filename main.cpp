#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main() {
    std::setlocale(LC_ALL, "");

    ABogomaz::MenuItem study_summ = { "1 - давай складывать!", ABogomaz::study_summ };
    ABogomaz::MenuItem study_subtract = { "2 - давай вычитать!", ABogomaz::study_subtract };
    ABogomaz::MenuItem study_multiply = { "3 - давай умножать!", ABogomaz::study_multiply };
    ABogomaz::MenuItem study_divide = { "4 - давай делить!", ABogomaz::study_divide };
    ABogomaz::MenuItem study_go_back = { "0 - хочу обратно! ", ABogomaz::study_go_back };

    ABogomaz::MenuItem* study_children[] = {
        &study_go_back,
        &study_summ,
        &study_subtract,
        &study_multiply,
        &study_divide
    };

    const int study_size = sizeof(study_children) / sizeof(study_children[0]);

    ABogomaz::MenuItem study = { "1 - вперед за знаниями!", ABogomaz::show_menu, study_children, study_size };
    ABogomaz::MenuItem exit = { "0 - майнкрафт ждет меня...", ABogomaz::exit };

    ABogomaz::MenuItem* main_children[] = { &exit, &study };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);

    ABogomaz::MenuItem main = { nullptr, ABogomaz::show_menu, main_children, main_size };

    study_summ.parent = &study;
    study_subtract.parent = &study;
    study_multiply.parent = &study;
    study_divide.parent = &study;
    study_go_back.parent = &study;

    study.parent = &main;
    exit.parent = &main;

    const ABogomaz::MenuItem* current = &main;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}
