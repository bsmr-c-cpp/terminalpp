#ifndef TERMINALPP_MODELS_DEFAULT_LIST_MODEL_HPP_
#define TERMINALPP_MODELS_DEFAULT_LIST_MODEL_HPP_

#include "terminalpp/core.hpp"
#include <vector>

namespace terminalpp { namespace models {

//* =========================================================================
/// \brief A class that encapsulates an abstract list of things, backed by
/// a vector<> for storage.
//* =========================================================================
template <class Element>
class default_list_model
{
public :
    //* =====================================================================
    /// \brief Returns the number of elements in the list.
    //* =====================================================================
    u32 size() const
    {
        return storage_.size();
    }

    //* =====================================================================
    /// \brief Adds an element to the list.
    //* =====================================================================
    void add(Element const &element)
    {
        storage_.push_back(element);
    }

    //* =====================================================================
    /// \brief Adds an element to the list.
    //* =====================================================================
    void add(Element &&element)
    {
        storage_.push_back(element);
    }

    //* =====================================================================
    /// \brief Returns an element from the list at the specified index.
    //* =====================================================================
    Element &get(u32 index)
    {
        return storage_[index];
    }

    //* =====================================================================
    /// \brief Returns an element from the list at the specified index.
    //* =====================================================================
    Element const &get(u32 index) const
    {
        return storage_[index];
    }

    //* =====================================================================
    /// \brief Removes the element at the specified index.
    //* =====================================================================
    void remove(u32 index)
    {
        storage_.erase(storage_.begin() + index);
    }

private :
    std::vector<Element> storage_;
};

}}

#endif
