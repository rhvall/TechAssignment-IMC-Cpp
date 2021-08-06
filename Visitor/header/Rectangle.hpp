//
//  Rectangle.cpp
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

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <tuple>
#include <string>
#include "Shape.hpp"

// Rectangle is a subclass of Shape that has one properties: side.
// Properties are private to enforce object creation with the expected values and
// possible value verification, which could be done at compile time using
// dependent types.
struct Rectangle : Shape
{
private:
    float side = 0;
    
public:
    Rectangle(float side = 0);
    const std::tuple<std::string, float, float> getProperties() const override;
    virtual const std::string acceptVisit(const AbstractAreaVisitor &visitor) override;
};

#endif /* Rectangle_hpp */
