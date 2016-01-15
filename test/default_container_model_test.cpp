#include <terminalpp/models/default_container_model.hpp>
#include <terminalpp/models/container_model.hpp>
#include <terminalpp/views/brush_view.hpp>
#include <gtest/gtest.h>

TEST(default_container_model_test, default_container_model_is_a_container_model)
{
    terminalpp::models::container_model model{
        terminalpp::models::default_container_model{}};
}

TEST(default_container_model_test, a_new_default_container_model_is_empty)
{
    terminalpp::models::container_model model{
        terminalpp::models::default_container_model{}};

    ASSERT_EQ(terminalpp::u32{0}, model.size());
}

TEST(default_container_model_test, adding_a_view_to_an_empty_container_adds_a_view)
{
    terminalpp::models::container_model model{
        terminalpp::models::default_container_model{}};


    model.add(
        terminalpp::views::view{
            terminalpp::views::brush_view{}},
        {});

    ASSERT_EQ(terminalpp::u32{1}, model.size());
}
