#include "terminalpp/layouts/grid_layout.hpp"

namespace terminalpp { namespace layouts {

namespace {
    
// ==========================================================================
// INCREMENT_OF_DIMENSION
// ==========================================================================
terminalpp::point increment_of_dimension(
    terminalpp::point current_dimension,
    terminalpp::extent const &dimensions)
{
    ++current_dimension.x;
    
    if ((current_dimension.x % dimensions.width) == 0)
    {
        current_dimension.x = 0;
        ++current_dimension.y;
    }
    
    if ((current_dimension.y % dimensions.height) == 0)
    {
        current_dimension.y = 0;
    }
    
    return current_dimension;
}

}

// ==========================================================================
// GET_PREFERRED_SIZE
// ==========================================================================
terminalpp::extent grid_layout::get_preferred_size(
    std::vector<terminalpp::extent> const &preferred_sizes,
    std::vector<boost::any>         const &hints) const
{
    terminalpp::extent result;

    for(auto const &preferred_size : preferred_sizes)
    {
        result.width  = std::max(result.width, preferred_size.width);
        result.height = std::max(result.height, preferred_size.height);
    }
    
    result.width  *= dimensions_.width;
    result.height *= dimensions_.height;
    
    return result;
}

// ==========================================================================
// DO_LAYOUT
// ==========================================================================
std::vector<terminalpp::rectangle> grid_layout::do_layout(
    std::vector<terminalpp::extent> const &preferred_sizes,
    std::vector<boost::any>         const &hints,
    terminalpp::extent                     size) const
{
    std::vector<terminalpp::rectangle> result;
    
    terminalpp::extent const size_per_view = {
        size.width / dimensions_.width,
        size.height / dimensions_.height
    };

    terminalpp::extent const total_excess = {
        size.width % dimensions_.width,
        size.height % dimensions_.height
    };
    
    terminalpp::point current_dimension;
    for (auto const &preferred_size : preferred_sizes)
    {
        auto const next_dimension = 
            increment_of_dimension(current_dimension, dimensions_);

        auto const excess = terminalpp::extent{
            next_dimension.x == 0 ? total_excess.width : 0,
            (next_dimension.x == 0 && next_dimension.y == 0) 
                                  ? total_excess.height : 0
        };
        
        result.push_back(
            {
                {
                    size_per_view.width * current_dimension.x,
                    size_per_view.height * current_dimension.y
                },
                {
                    size_per_view.width + excess.width,
                    size_per_view.height + excess.height
                }
            });
        
        current_dimension = next_dimension;
    }
    
    return result;
}

}}

