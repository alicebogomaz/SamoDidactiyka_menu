#include <cstddef>

#include "menu_items.hpp"

#include "menu_functions.hpp"

const ABogomaz::MenuItem ABogomaz::STUDY_SUMM = {
    "1 - давай складывать!", ABogomaz::study_summ, &ABogomaz::STUDY
};
const ABogomaz::MenuItem ABogomaz::STUDY_SUBTRACT = {
    "2 - давай вычитать!", ABogomaz::study_subtract, &ABogomaz::STUDY
};
const ABogomaz::MenuItem ABogomaz::STUDY_MULTIPLY = {
    "3 - давай умножать!", ABogomaz::study_multiply, &ABogomaz::STUDY
};
const ABogomaz::MenuItem ABogomaz::STUDY_DIVIDE = {
    "4 - давай делить!", ABogomaz::study_divide, &ABogomaz::STUDY
};
const ABogomaz::MenuItem ABogomaz::STUDY_GO_BACK = {
    "0 - хочу обратно! ", ABogomaz::study_go_back,  &ABogomaz::STUDY
};

namespace {
    const ABogomaz::MenuItem* const study_children[] = {
        &ABogomaz::STUDY_GO_BACK,
        &ABogomaz::STUDY_SUMM,
        &ABogomaz::STUDY_SUBTRACT,
        &ABogomaz::STUDY_MULTIPLY,
        &ABogomaz::STUDY_DIVIDE
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const ABogomaz::MenuItem ABogomaz::STUDY = {
    "1 - вперед за знаниями!", ABogomaz::show_menu, &ABogomaz::MAIN, study_children, study_size
};

const ABogomaz::MenuItem ABogomaz::EXIT = {
    "0 - майнкрафт ждет меня...", ABogomaz::exit, &ABogomaz::MAIN
};

namespace {
    const ABogomaz::MenuItem* const main_children[] = {
      &ABogomaz::EXIT,
      &ABogomaz::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ABogomaz::MenuItem ABogomaz::MAIN = {
    nullptr, ABogomaz::show_menu, nullptr, main_children, main_size
};
