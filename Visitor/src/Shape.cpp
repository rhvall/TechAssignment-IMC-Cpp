//
//  Shape.cpp
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

#include "Shape.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

Shape::~Shape()
{
}

Shape *Shape::generateShapes(ShapeList type, std::uniform_real_distribution<float> valDist, std::mt19937 generator)
{
    float genericSide = valDist(generator);
    float height = valDist(generator);
    
    Shape *s;
    switch (type)
    {
        case TriangleShape:
            s = new Triangle(genericSide, height);
            break;
        case RectangleShape:
            s = new Rectangle(genericSide);
            break;
        case CircleShape:
        default:
            s = new Circle(genericSide);
            break;
    }
    
    return s;
}
