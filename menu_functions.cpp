#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "menu_functions.hpp"

namespace {
    // Simple ANSI color helpers (skip colors if NO_COLOR is set).
    constexpr const char* CLR_RESET = "\x1b[0m";
    constexpr const char* CLR_BREADCRUMB = "\x1b[36m";
    constexpr const char* CLR_TITLE = "\x1b[33m";
    constexpr const char* CLR_HINT = "\x1b[90m";
    bool use_color() {
        return std::getenv("NO_COLOR") == nullptr;
    }
    std::string tint(const std::string& text, const char* color) {
        if (!use_color()) return text;
        return std::string(color) + text + CLR_RESET;
    }

    // Clear the console before drawing the next screen.
    void clear_screen() {
#ifdef _WIN32
        std::system("cls");
#else
        std::cout << "\x1B[2J\x1B[H";
#endif
    }

    // Walk up the parent chain to build breadcrumb text like "Main > Study > Algebra".
    std::string build_breadcrumb(const ABogomaz::MenuItem* current) {
        std::vector<std::string> titles;
        const ABogomaz::MenuItem* cursor = current;
        while (cursor) {
            titles.push_back(cursor->title);
            auto parent = cursor->getParent();
            cursor = parent ? parent.get() : nullptr;
        }
        std::string breadcrumb;
        for (auto it = titles.rbegin(); it != titles.rend(); ++it) {
            if (!breadcrumb.empty()) {
                breadcrumb += " > ";
            }
            breadcrumb += *it;
        }
        return breadcrumb;
    }

    // After showing a leaf, wait for Enter so the user can read the output.
    void wait_for_enter() {
        // Discard any leftover characters (e.g., newline after numeric input)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nPress Enter to return...";
        std::string _;
        std::getline(std::cin, _);
    }
}

const ABogomaz::MenuItem* ABogomaz::show_menu(const MenuItem* current) {
    clear_screen();
    std::cout << tint(build_breadcrumb(current), CLR_BREADCRUMB) << std::endl;
    std::cout << "\n";
    std::cout << tint("== " + current->title + " ==", CLR_TITLE) << std::endl;

    if (!current->hasChildren()) {
        // Leaf nodes delegate to their handler immediately.
        std::cout << "\n---\n";
        return current->func ? current->func(current) : current;
    }

    std::cout << "\n";

    for (size_t i = 0; i < current->children.size(); ++i) {
        // The declaration in menu_definition.cpp always puts back/exit at index 0.
        std::cout << i << " - " << current->children[i]->title << std::endl;
    }

    std::cout << "\nSelect option: ";

    int user_input;
    if (!(std::cin >> user_input)) {
        // Handle non-numeric input gracefully and stay on the same menu.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number." << std::endl;
        return current;
    }

    if (user_input >= 0 && user_input < static_cast<int>(current->children.size())) {
        return current->children[user_input].get();
    }

    std::cout << "Invalid option: " << user_input << std::endl;
    return current;
}

const ABogomaz::MenuItem* ABogomaz::exit(const MenuItem* current) {
    // Immediate process termination when user selects Exit at the root.
    std::exit(0);
}

const ABogomaz::MenuItem* ABogomaz::study_summ(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    wait_for_enter();
    if (auto parent = current->getParent()) {
        return parent.get();
    }
    return current;
}

const ABogomaz::MenuItem* ABogomaz::study_subtract(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    wait_for_enter();
    if (auto parent = current->getParent()) {
        return parent.get();
    }
    return current;
}

const ABogomaz::MenuItem* ABogomaz::study_multiply(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    wait_for_enter();
    if (auto parent = current->getParent()) {
        return parent.get();
    }
    return current;
}

const ABogomaz::MenuItem* ABogomaz::study_divide(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl;
    wait_for_enter();
    if (auto parent = current->getParent()) {
        return parent.get();
    }
    return current;
}

const ABogomaz::MenuItem* ABogomaz::study_go_back(const MenuItem* current) {
    // Return to the parent or to the parent's parent, matching "Back" semantics.
    if (auto parent = current->getParent()) {
        if (auto grandparent = parent->getParent()) {
            return grandparent.get();
        }
        return parent.get();
    }
    return current;
}
