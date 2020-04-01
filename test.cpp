#include <memory>

struct Foo {
    void foo() {}
};

namespace ns {

struct Bar {
    void bar() {}
};

/** @callgraph */
void use_shared_ptr_unqualified() {
    std::shared_ptr<Foo> foo;
    foo->foo();
    std::shared_ptr<Bar> bar;
    bar->bar();
}

/** @callgraph */
void use_shared_ptr_qualified() {
    std::shared_ptr<Foo> foo;
    foo->foo();
    std::shared_ptr<ns::Bar> bar;
    bar->bar();
}

struct Test {
    /** @callgraph */
    void use_shared_ptr_unqualified() {
        std::shared_ptr<Foo> foo;
        foo->foo();
        std::shared_ptr<Bar> bar;
        bar->bar();
    }

    /** @callgraph */
    void use_shared_ptr_qualified() {
        std::shared_ptr<Foo> foo;
        foo->foo();
        std::shared_ptr<ns::Bar> bar;
        bar->bar();
    }
};

}
