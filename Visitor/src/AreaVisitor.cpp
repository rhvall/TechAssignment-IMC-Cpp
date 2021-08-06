//
//  AreaVisitor.cpp
//  IMC Job Test
//
//  Created by RHVT on 07/07/2021.
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

#include <math.h>
#include <sstream>
#include <tuple>

#include "AreaVisitor.hpp"

// It calculates its area using the formula (base * height) / 2.
const std::string AreaVisitor::visitShape(const Triangle &t) const
{
    std::ostringstream strStream;
    std::string name;
    float base, height;
    std::tie(name, base, height) = t.getProperties();
    float area = (base * height) / 2;
    strStream << name << " with base: " << base << ", height: " << height << " and area: " << area;
    return strStream.str();
}

// It calculates its area using the formula side * side.
const std::string AreaVisitor::visitShape(const Rectangle &t) const
{
    std::ostringstream strStream;
    std::string name = std::get<0>(t.getProperties());
    float side = std::get<1>(t.getProperties());
    float area = side * side;
    strStream << name << " with side: " << side << " and area: " << area;
    return strStream.str();
}

// It calculates its area using the formula M_PI * radius * radius.
const std::string AreaVisitor::visitShape(Circle const &t) const
{
    std::ostringstream strStream;
    std::string name = std::get<0>(t.getProperties());
    float radius = std::get<1>(t.getProperties());
    float area = M_PI * radius * radius;
    strStream << name << " with radius: " << radius << " and area: " << area;
    return strStream.str();
}
