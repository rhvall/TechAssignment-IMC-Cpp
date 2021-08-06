//
//  Shape.hpp
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

#ifndef Shape_hpp
#define Shape_hpp

#include <tuple>
#include <random>

struct AbstractAreaVisitor;

// This enum help us to enumerate the sub-structs related to shape,
// that makes it easier to count between different elements in a vector
enum ShapeList
{
    TriangleShape = 0,
    CircleShape = 1,
    RectangleShape = 2,
    MaxListShape = 3
};

// Shape is an abstract structure with two function that must be implemented
// by substructs: getProperties and acceptVisit
// A struct was chosen instead of a class becase they can not have null values,
// something expected in a shape. Also, these memory arrangements are simple,
// therefore no need for complex constructor and destructors.
struct Shape
{
public:
    virtual ~Shape() = 0;
    // This function arranges the different types of properties embeded in a
    // substruct in a generic way. The string element allows the shape to be
    // named and differentiated from others.
    virtual const std::tuple<std::string, float, float> getProperties() const = 0;
    
    // This function enables the visitor pattern to this struct, by simply
    // receiving an instance variable to perform the Area calculation and returning
    // an string with all the shape details.
    virtual const std::string acceptVisit(const AbstractAreaVisitor &visitor) = 0;
    
    // It allows to generate generic pointers up to MaxListShape (non-inclusive) with
    // generic properties. However, this function creates new instances in the heap,
    // which could leak if they are not properly handled.
    static Shape *generateShapes(ShapeList type, std::uniform_real_distribution<float> valDist, std::mt19937 generator);
};


#endif /* Shape_hpp */
