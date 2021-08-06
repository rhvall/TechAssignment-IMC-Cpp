//
//  Circle.hpp
//  VisitorXcode
//
//  Created by RH VT on 7/8/21.
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

#ifndef Circle_hpp
#define Circle_hpp

#include <tuple>
#include <string>
#include "Shape.hpp"

// Circle is a subclass of Shape that has a radious property.
// It calculates its area using the formula (pi * r ^ 2). Properties
// are private to enforce object creation with the expected values and
// possible value verification, which could be done at compile time using
// dependent types.
struct Circle : Shape
{
private:
    float radius = 0;

public:
    Circle(float radiusVal = 0);
    const std::tuple<std::string, float, float> getProperties() const override;
    virtual const std::string acceptVisit(const AbstractAreaVisitor &visitor) override;
};


#endif /* Circle_hpp */
