//
//  AreaVisitor.hpp
//  IMC Job Test
//
//  Created by RHVT on 08/07/2021.
//  Copyright © 2021 R. All rights reserved.
//

// //////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3 or later.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
// //////////////////////////////////////////////////////////

#ifndef AreaVisitor_hpp
#define AreaVisitor_hpp

#include <string>
#include "Shape.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

struct AbstractAreaVisitor
{
public:
    virtual const std::string visitShape(const Triangle &t) const = 0;
    virtual const std::string visitShape(const Rectangle &r) const = 0;
    virtual const std::string visitShape(const Circle &c) const = 0;
};

struct AreaVisitor : AbstractAreaVisitor
{
// Even though structs are public by default...
public:
    // visitShape transform the properties of a shape into a string
    // that can be used to display on a console or file.
    virtual const std::string visitShape(const Triangle &t) const override;
    virtual const std::string visitShape(const Rectangle &r) const override;
    virtual const std::string visitShape(const Circle &c) const override;
    
    // NOTE: the visitShape methods do not modify anything the passed variable,
    // that's why they take "const &". Also, these functions are "pure"
    // in other words, for the same input, they will always return the
    // same output.
};

#endif /* AreaVisitor_hpp */
