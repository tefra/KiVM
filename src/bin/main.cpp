#include <kivm/classLoader.h>
#include <kivm/oop/instanceKlass.h>

int main() {
    using namespace kivm;
    auto *a = (InstanceKlass *) BootstrapClassLoader::get()->loadClass(L"java/lang/CloneNotSupportedException");
    printf("loaded\n");
    return 0;
}