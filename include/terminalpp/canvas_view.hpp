#pragma once

#include "terminalpp/element.hpp"
#include "terminalpp/extent.hpp"

namespace terminalpp {

class canvas;

//* =========================================================================
/// \brief A sub-view into a canvas that only allows reading and writing
/// to a its elements; not operations that would affect the entire canvas.
//* =========================================================================
class TERMINALPP_EXPORT canvas_view
{
public :
    //* =====================================================================
    /// \brief A proxy into a row of elements on the canvas
    //* =====================================================================
    class row_proxy
    {
    public :
        // ==================================================================
        // CONSTRUCTOR
        // ==================================================================
        row_proxy(
            canvas_view &cvs, coordinate_type column, coordinate_type row);

        // ==================================================================
        // OPERATOR=
        // ==================================================================
        row_proxy &operator=(row_proxy const &other);

        // ==================================================================
        // OPERATOR=
        // ==================================================================
        row_proxy &operator=(element const &value);

        // ==================================================================
        // CONVERSION OPERATOR: ELEMENT
        // ==================================================================
        operator element &();

        // ==================================================================
        // CONVERSION OPERATOR: ELEMENT
        // ==================================================================
        operator element const &() const;

    private :
        canvas_view &canvas_;
        coordinate_type column_;
        coordinate_type row_;
    };

    //* =====================================================================
    /// \brief A proxy into a column of elements on the canvas
    //* =====================================================================
    class column_proxy
    {
    public :
        // ==================================================================
        // CONSTRUCTOR
        // ==================================================================
        column_proxy(canvas_view &cvs, coordinate_type column);

        // ==================================================================
        // OPERATOR[]
        // ==================================================================
        row_proxy operator[](coordinate_type row);

    private :
        canvas_view &canvas_;
        coordinate_type column_;
    };

    //* =====================================================================
    /// \brief A constant proxy into a column of elements on the canvas
    //* =====================================================================
    class const_column_proxy
    {
    public :
        // ==================================================================
        // CONSTRUCTOR
        // ==================================================================
        const_column_proxy(canvas_view const &cvs, coordinate_type column);

        // ==================================================================
        // OPERATOR[]
        // ==================================================================
        element const &operator[](coordinate_type row) const;

    private :
        canvas_view const &canvas_;
        coordinate_type column_;
    };

    //* =====================================================================
    /// \brief Constructor
    //* =====================================================================
    explicit canvas_view(canvas &cvs);

    //* =====================================================================
    /// \brief Offsets the canvas by a certain amount, causing it to become
    /// a view with the offset location as a basis.
    //* =====================================================================
    void offset_by(extent offset);

    //* =====================================================================
    /// \brief Returns the size of the canvas.
    //* =====================================================================
    extent size() const;

    //* =====================================================================
    /// \brief A subscript operator into a column
    //* =====================================================================
    column_proxy operator[](coordinate_type column);

    //* =====================================================================
    /// \brief A subscript operator into a column
    //* =====================================================================
    const_column_proxy operator[](coordinate_type column) const;

private :
    //* =====================================================================
    /// \brief Set the value of an element.
    //* =====================================================================
    void set_element(
        coordinate_type column, coordinate_type row, element const &value);

    //* =====================================================================
    /// \brief Get the value of an element.
    //* =====================================================================
    element &get_element(coordinate_type column, coordinate_type row);

    //* =====================================================================
    /// \brief Get the value of an element.
    //* =====================================================================
    element const &get_element(
        coordinate_type column, coordinate_type row) const;

    canvas &canvas_;
    extent  offset_;
};

}
