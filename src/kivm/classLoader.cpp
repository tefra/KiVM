//
// Created by kiva on 2018/2/27.
//

#include <unordered_map>
#include <kivm/classLoader.h>
#include <kivm/klass.h>
#include <shared/lock.h>

namespace kivm {
    static Lock &get_bootstrap_lock() {
        static Lock lock;
        return lock;
    }

    static std::unordered_map<String, Klass *> &get_bootstrap_classes() {
        static std::unordered_map<String, Klass *> bootstrap_classes;
        return bootstrap_classes;
    }

    BootstrapClassLoader *BootstrapClassLoader::get_class_loader() {
        static BootstrapClassLoader classLoader;
        return &classLoader;
    }

    Klass *BootstrapClassLoader::loadClass(const String &class_name) {
        LockGuard guard(get_bootstrap_lock());
        auto &cache_map = get_bootstrap_classes();

        // check whether class is already loaded
        auto iter = cache_map.find(class_name);
        if (iter != cache_map.end()) {
            return iter->second;
        }

        // Okay, let's load it.
        // TODO: find and load classes.
        return nullptr;
    }
}