#include <terminalpp/views/container_view.hpp>
#include <terminalpp/views/view.hpp>
#include <gtest/gtest.h>

TEST(container_view_test, container_view_is_a_view)
{
    terminalpp::views::view view{terminalpp::views::container_view{}};
}