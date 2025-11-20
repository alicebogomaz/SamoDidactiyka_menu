#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "menu_functions.hpp"

namespace {
    // Type aliases to keep the description readable.
    using ABogomaz::MenuItem;
    using MenuHandler = std::function<const MenuItem*(const MenuItem*)>;

    // A lightweight description of a node in the menu (title + handler + children).
    struct MenuSpec {
        std::string title;
        MenuHandler func;
        std::vector<MenuSpec> children;
    };

    // Recursively build the real MenuItem tree from the declarative MenuSpec.
    std::shared_ptr<MenuItem> build_menu(const MenuSpec& spec,
                                         std::weak_ptr<MenuItem> parent = {}) {
        auto node = std::make_shared<MenuItem>(spec.title, spec.func);
        node->parent = parent;

        for (const auto& child_spec : spec.children) {
            node->children.push_back(build_menu(child_spec, node));
        }

        return node;
    }
}

std::shared_ptr<ABogomaz::MenuItem> ABogomaz::create_menu() {
    const MenuSpec menu_definition{
        "Main Menu",
        show_menu,
        {
            {"Exit", exit, {}},
            {
                "Study Menu",
                show_menu,
                {
                    // Index 0 is always Back at non-root levels.
                    {"Back", study_go_back, {}},
                    {
                        "Arithmetic",
                        show_menu,
                        {
                            {"Back", study_go_back, {}},
                            {
                                "Addition Modules",
                                show_menu,
                                {
                                    // Leaves: show text, wait for Enter, then return to parent.
                                    {"Back", study_go_back, {}},
                                    {"Single-digit sums", study_summ, {}},
                                    {"Double-digit sums", study_summ, {}},
                                    {"Word problems", study_summ, {}},
                                },
                            },
                            {
                                "Multiplication Modules",
                                show_menu,
                                {
                                    {"Back", study_go_back, {}},
                                    {"Times tables", study_multiply, {}},
                                    {"Multi-digit products", study_multiply, {}},
                                },
                            },
                        },
                    },
                    {
                        "Algebra",
                        show_menu,
                        {
                            {"Back", study_go_back, {}},
                            // The pattern repeats: nested topics, then lessons as leaves.
                            {
                                "Linear Equations",
                                show_menu,
                                {
                                    {"Back", study_go_back, {}},
                                    {"One-step equations", study_subtract, {}},
                                    {"Two-step equations", study_divide, {}},
                                },
                            },
                            {
                                "Inequalities",
                                show_menu,
                                {
                                    {"Back", study_go_back, {}},
                                    {"Solve inequalities", study_divide, {}},
                                    {"Graph solutions", study_subtract, {}},
                                },
                            },
                        },
                    },
                },
            },
        },
    };

    return build_menu(menu_definition);
}
