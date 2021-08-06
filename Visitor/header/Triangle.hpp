//
//  Triangle.hpp
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

#ifndef Triangle_hpp
#define Triangle_hpp

#include <tuple>
#include <string>
#include "Shape.hpp"

// Triangle is a subclass of Shape that has two properties: base and height.
// It calculates its area using the formula (base * height) / 2. Properties
// are private to enforce object creation with the expected values and
// possible value verification, which could be done at compile time using
// dependent types.
struct Triangle : Shape
{
private:
    float base = 0;
    float height = 0;

public:
    Triangle(float baseVal = 0, float heightVal = 0);
    virtual const std::tuple<std::string, float, float> getProperties() const override;
    virtual const std::string acceptVisit(const AbstractAreaVisitor &visitor) override;
};

#endif /* Triangle_hpp */
