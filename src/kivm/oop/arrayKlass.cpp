//
// Created by kiva on 2018/3/1.
//

#include <kivm/oop/arrayKlass.h>

namespace kivm {

    ArrayKlass::ArrayKlass(ClassLoader *class_loader, int dimension, ClassType class_type) {
        this->_class_loader = class_loader;
        this->_dimension = dimension;
        this->set_type(ClassType::OBJECT_ARRAY_CLASS);
    }

    TypeArrayKlass::TypeArrayKlass(ClassLoader *class_loader, int dimension, ValueType component_type)
            : ArrayKlass(class_loader, dimension, ClassType::TYPE_ARRAY_CLASS) {
        this->_component_type = component_type;
    }

    ObjectArrayKlass::ObjectArrayKlass(ClassLoader *class_loader, int dimension, InstanceKlass *component_type)
            : ArrayKlass(class_loader, dimension, ClassType::OBJECT_ARRAY_CLASS) {
        this->_component_type = component_type;
    }
}