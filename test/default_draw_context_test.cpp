#include <terminalpp/views/default_draw_context.hpp>
#include <terminalpp/views/draw_context.hpp>
#include <terminalpp/canvas.hpp>
#include <terminalpp/canvas_view.hpp>
#include <gtest/gtest.h>

TEST(default_draw_context_test, default_draw_context_is_a_draw_context)
{
    terminalpp::canvas canvas{{}};
    terminalpp::canvas_view canvas_view(canvas);

    terminalpp::views::draw_context dc{
        terminalpp::views::default_draw_context{canvas_view}};
}