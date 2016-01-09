#include <terminalpp/layouts/grid_layout.hpp>
#include <terminalpp/layouts/layout.hpp>
#include <gtest/gtest.h>

TEST(grid_layout_test, grid_layout_is_layout)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};
}

TEST(grid_layout_test, preferred_size_of_a_layout_with_no_views_is_zero)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};

    auto expected = terminalpp::extent{0, 0};
    auto result   = layout.get_preferred_size({}, {});
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, preferred_size_of_a_1x1_grid_with_one_view_is_the_preferred_size_of_the_view)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};
        
    auto expected = terminalpp::extent{5, 5};
    auto result   = layout.get_preferred_size({expected}, {{}});
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, preferred_size_of_a_2x1_grid_with_two_views_is_the_twice_the_maximum_width_and_the_maximum_height)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{2, 1}}};
        
    auto view0_preferred_size = terminalpp::extent{3, 5};
    auto view1_preferred_size = terminalpp::extent{5, 3};
    auto expected = terminalpp::extent{10, 5};
    auto result = layout.get_preferred_size(
        { view0_preferred_size, view1_preferred_size },
        { {},                   {}                   });
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, preferred_size_of_a_1x2_grid_with_two_views_is_the_maximum_width_and_twice_the_maximum_height)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 2}}};
        
    auto view0_preferred_size = terminalpp::extent{3, 5};
    auto view1_preferred_size = terminalpp::extent{5, 3};
    auto expected = terminalpp::extent{5, 10};
    auto result = layout.get_preferred_size(
        { view0_preferred_size, view1_preferred_size },
        { {},                   {}                   });
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, preferred_size_of_a_2x2_grid_with_four_views_is_twice_the_maximum_width_and_twice_the_maximum_height)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{2, 2}}};
        
    auto view0_preferred_size = terminalpp::extent{3, 5};
    auto view1_preferred_size = terminalpp::extent{5, 3};
    auto view2_preferred_size = terminalpp::extent{2, 6};
    auto view3_preferred_size = terminalpp::extent{4, 8};
    
    auto expected = terminalpp::extent{10, 16};
    auto result = layout.get_preferred_size(
        {
            view0_preferred_size, 
            view1_preferred_size, 
            view2_preferred_size, 
            view3_preferred_size 
        },
        {
            {},                   
            {},
            {},
            {}
        });
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, laying_out_grid_with_no_views_returns_empty_vector)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};
        
    auto expected = std::vector<terminalpp::rectangle>{};
    auto result   = layout.do_layout({}, {}, {1, 1});
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_1x1_grid_with_view_whose_preferred_size_matches_size_returns_size)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};
        
    auto size = terminalpp::extent{5, 5};
    auto preferred_size = size;
    
    auto expected = std::vector<terminalpp::rectangle>{
        {{}, size}
    };
    
    auto result = layout.do_layout({preferred_size}, {{}}, size);
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_1x1_grid_with_view_whose_preferred_size_is_smaller_returns_size)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};

    auto size = terminalpp::extent{5, 5};
    auto preferred_size = terminalpp::extent{3, 3};
    
    auto expected = std::vector<terminalpp::rectangle>{
        {{}, size}
    };
    
    auto result = layout.do_layout({preferred_size}, {{}}, size);
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_1x1_grid_with_view_whose_preferred_size_is_larger_returns_size)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 1}}};

    auto size = terminalpp::extent{5, 5};
    auto preferred_size = terminalpp::extent{9, 9};
    
    auto expected = std::vector<terminalpp::rectangle>{
        {{}, size}
    };
    
    auto result = layout.do_layout({preferred_size}, {{}}, size);
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_2x1_grid_splits_width_in_half_and_positions_second_half_way_across)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{2, 1}}};
        
    auto size = terminalpp::extent{10, 10};
    auto expected = std::vector<terminalpp::rectangle>{
        {{0, 0}, {5, 10}},
        {{5, 0}, {5, 10}}
    };
    
    auto result = layout.do_layout({{}, {}}, {{}, {}}, size);
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_1x2_grid_splits_heights_in_half_and_positions_second_half_way_down)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{1, 2}}};
        
    auto size = terminalpp::extent{10, 10};
    auto expected = std::vector<terminalpp::rectangle>{
        {{0, 0}, {10, 5}},
        {{0, 5}, {10, 5}}
    };
    
    auto result = layout.do_layout({{}, {}}, {{}, {}}, size);
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_2x2_grid_splits_width_and_heights_in_half)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{2, 2}}};
        
    auto size = terminalpp::extent{10, 10};
    auto expected = std::vector<terminalpp::rectangle>{
        {{0, 0}, {5, 5}},
        {{5, 0}, {5, 5}},
        {{0, 5}, {5, 5}},
        {{5, 5}, {5, 5}}
    };
    
    auto result = layout.do_layout({{}, {}, {}, {}}, {{}, {}, {}, {}}, size);
    
    ASSERT_EQ(expected, result);
}

TEST(grid_layout_test, layout_of_unevenly_divisible_2x2_grid_gives_excess_to_final_components)
{
    terminalpp::layouts::layout layout{
        terminalpp::layouts::grid_layout{{2, 2}}};
        
    auto size = terminalpp::extent{11, 11};
    auto expected = std::vector<terminalpp::rectangle>{
        {{0, 0}, {5, 5}},
        {{5, 0}, {6, 5}},
        {{0, 5}, {5, 5}},
        {{5, 5}, {6, 6}}
    };

    auto result = layout.do_layout({{}, {}, {}, {}}, {{}, {}, {}, {}}, size);
    
    ASSERT_EQ(expected, result);
}

// TODO: Larger grids should have excess spread out amongst them.
// But most grids are small.