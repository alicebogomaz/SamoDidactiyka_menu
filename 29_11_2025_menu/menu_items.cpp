#include <cstddef>

#include "menu.hpp"
#include "menu_items.hpp"
#include "menu_func.hpp"

const ABogomaz::MenuItem ABogomaz::READ_BACK = {
    "0 - Выйти в предыдущее меню", ABogomaz::go_back, &ABogomaz::PUSHKIN
};

const ABogomaz::MenuItem ABogomaz::DUBROVSKY = {
    "1 - Дубровский", ABogomaz::dubrovsky, &ABogomaz::PUSHKIN
};

const ABogomaz::MenuItem ABogomaz::ONEGIN = {
    "2 - Евгений Онегин", ABogomaz::onegin, &ABogomaz::PUSHKIN
};

const ABogomaz::MenuItem ABogomaz::WINTER = {
    "3 - Зимний вечер", ABogomaz::winter, &ABogomaz::PUSHKIN
};

namespace {
    const ABogomaz::MenuItem* pushkin_children[] = {
        &ABogomaz::READ_BACK,
        &ABogomaz::DUBROVSKY,
        &ABogomaz::ONEGIN,
        &ABogomaz::WINTER
    };
    const int pushkin_count = sizeof(pushkin_children) / sizeof(pushkin_children[0]);
}

const ABogomaz::MenuItem ABogomaz::GO_BACK = {
    "0 - Выйти в главное меню", ABogomaz::go_back, &ABogomaz::POETS
};

const ABogomaz::MenuItem ABogomaz::PUSHKIN = {
    "1 - Читать Пушкина", ABogomaz::show_poems, &ABogomaz::POETS, pushkin_children, pushkin_count
};

const ABogomaz::MenuItem ABogomaz::LERMONTOV = {
    "2 - Читать Лермонтова", ABogomaz::show_poems, &ABogomaz::POETS
};

const ABogomaz::MenuItem ABogomaz::KRYLOV = {
    "3 - Читать Крылова", ABogomaz::show_poems, &ABogomaz::POETS
};

namespace {
    const ABogomaz::MenuItem* poets_children[] = {
        &ABogomaz::GO_BACK,
        &ABogomaz::PUSHKIN,
        &ABogomaz::LERMONTOV,
        &ABogomaz::KRYLOV
    };
    const int poets_count = sizeof(poets_children) / sizeof(poets_children[0]);
}

const ABogomaz::MenuItem ABogomaz::EXIT = {
    "0 - Завершить чтение", ABogomaz::exit, &ABogomaz::MAIN
};

const ABogomaz::MenuItem ABogomaz::POETS = {
    "1 - Русский писатели", ABogomaz::show_poets, &ABogomaz::MAIN, poets_children, poets_count
};

namespace {
    const ABogomaz::MenuItem* main_children[] = {
        &ABogomaz::EXIT,
        &ABogomaz::POETS
    };
    const int main_count = sizeof(main_children) / sizeof(main_children[0]);
}

const ABogomaz::MenuItem ABogomaz::MAIN = {
    nullptr, ABogomaz::show_main, nullptr, main_children, main_count
};
