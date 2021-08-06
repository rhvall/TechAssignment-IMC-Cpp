//
//  Cirle.cpp
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

#include "Circle.hpp"
#include "AreaVisitor.hpp"

Circle::Circle(float radiusVal):
    radius(radiusVal)
{
}

const std::tuple<std::string, float, float> Circle::getProperties() const
{
    return std::make_tuple("Circle", radius, 0);
}

const std::string Circle::acceptVisit(const AbstractAreaVisitor &visitor)
{
    return visitor.visitShape(*this);
}
