#include <terminalpp/models/default_list_model.hpp>
#include <terminalpp/models/list_model.hpp>
#include <gtest/gtest.h>

TEST(default_list_model_test, default_list_model_of_t_is_list_model_of_t)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};
}

TEST(default_list_model_test, a_new_default_list_model_is_empty)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};

    ASSERT_EQ(terminalpp::u32{0}, model.size());
}

TEST(default_list_model_test, adding_an_element_to_an_empty_list_adds_an_element)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};

    int const test_value = 7;
    model.add(test_value);

    ASSERT_EQ(terminalpp::u32{1}, model.size());
    ASSERT_EQ(test_value, model.get(0));
}

TEST(default_list_model_test, adding_an_element_to_a_non_empty_list_adds_an_element_to_the_end)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};

    int const test_value0 = 7;
    int const test_value1 = 8;
    model.add(test_value0);
    model.add(test_value1);

    ASSERT_EQ(terminalpp::u32{2}, model.size());
    ASSERT_EQ(test_value0, model.get(0));
    ASSERT_EQ(test_value1, model.get(1));
}

TEST(default_list_model_test, can_remove_an_element_from_the_beginning_of_the_list)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};

    int const test_value0 = 7;
    int const test_value1 = 8;
    model.add(test_value0);
    model.add(test_value1);

    model.remove(0);

    ASSERT_EQ(terminalpp::u32{1}, model.size());
    ASSERT_EQ(test_value1, model.get(0));
}

TEST(default_list_model_test, can_remove_an_element_from_the_end_of_the_list)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};

    int const test_value0 = 7;
    int const test_value1 = 8;
    model.add(test_value0);
    model.add(test_value1);

    model.remove(1);

    ASSERT_EQ(terminalpp::u32{1}, model.size());
    ASSERT_EQ(test_value0, model.get(0));
}

TEST(default_list_model_test, can_remove_an_element_from_the_middle_of_the_list)
{
    terminalpp::models::list_model<int> model{
        terminalpp::models::default_list_model<int>{}};

    int const test_value0 = 7;
    int const test_value1 = 8;
    int const test_value2 = 9;
    model.add(test_value0);
    model.add(test_value1);
    model.add(test_value2);

    model.remove(1);

    ASSERT_EQ(terminalpp::u32{2}, model.size());
    ASSERT_EQ(test_value0, model.get(0));
    ASSERT_EQ(test_value2, model.get(1));
}