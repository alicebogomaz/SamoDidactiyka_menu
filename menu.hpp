#pragma once

#include <vector>
#include <memory>
#include <functional>
#include <string>

namespace ABogomaz {
    // One node in the menu tree: stores the label, handler, children, and link to parent.
    struct MenuItem {
        std::string title; // Text shown for this menu entry.
        std::function<const MenuItem*(const MenuItem*)> func; // Function to call when this node is active.
        std::vector<std::shared_ptr<MenuItem>> children; // Child menu nodes (sub-items).
        std::weak_ptr<MenuItem> parent; // Back-link to the parent (weak to avoid ownership cycles).

        MenuItem(const std::string& title,
                 std::function<const MenuItem*(const MenuItem*)> func = nullptr)
            : title(title), func(func) {}

        // Does this node have any children to display?
        bool hasChildren() const {
            return !children.empty();
        }

        // Return a shared_ptr to the parent if it still exists; otherwise null.
        std::shared_ptr<MenuItem> getParent() const {
            return parent.lock();
        }
    };
}
