#ifndef TERMINALPP_MODELS_DEFAULT_CONTAINER_MODEL_HPP_
#define TERMINALPP_MODELS_DEFAULT_CONTAINER_MODEL_HPP_

#include "terminalpp/views/view.hpp"
#include <boost/any.hpp>
#include <vector>

namespace terminalpp {

namespace models {

class TERMINALPP_EXPORT default_container_model
{
public :
    u32 size() const;
    void add(
        terminalpp::views::view &&view,
        boost::any const &hint);

private :
    std::vector<terminalpp::views::view> views_;
    std::vector<boost::any>              hints_;
};

}}

#endif
