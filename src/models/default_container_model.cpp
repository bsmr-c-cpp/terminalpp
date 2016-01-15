#include "terminalpp/models/default_container_model.hpp"

namespace terminalpp { namespace models {

u32 default_container_model::size() const
{
    return views_.size();
}

void default_container_model::add(
    terminalpp::views::view &&view,
    boost::any const &hint)
{
    views_.push_back(std::move(view));
    hints_.push_back(hint);
}

}}
