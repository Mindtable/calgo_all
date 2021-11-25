#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AVLTree.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        AVLTree obj;
        ClassDeclaration() {
            obj;
        }
    };
}

TEST_F(ClassDeclaration, test_insert) {
    obj.insert(10);
    ASSERT_EQ(true, obj.search(10));
}

TEST_F(ClassDeclaration, test_delete) {
    obj.insert(10);
    obj.delete_value(10);
    ASSERT_EQ(false, obj.search(10));
}

TEST_F(ClassDeclaration, test_multiple) {
    obj.insert(3);
    obj.insert(1);
    obj.insert(2);
    ASSERT_EQ(0, obj.balance());
}

TEST_F(ClassDeclaration, test_next_n_prev) {
    obj.insert(3);
    obj.insert(1);
    obj.insert(2);
    ASSERT_EQ("none", obj.next(3));
    ASSERT_EQ("none", obj.prev(1));
    ASSERT_EQ("2", obj.prev(3));
}



