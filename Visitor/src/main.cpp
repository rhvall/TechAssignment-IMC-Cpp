//
//  main.cpp
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

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

#include "Shape.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "AreaVisitor.hpp"

std::mt19937 randomGenerator()
{
    std::random_device rd;
    // seed value is designed specifically to make initialization
    // parameters of std::mt19937 (instance of std::mersenne_twister_engine<>)
    // different across executions of application
    // source: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    return gen;
}

void randomizedShapeExample()
{
    std::mt19937 generator = randomGenerator();
    // This distribution will manage how many Shapes will be created
    std::uniform_int_distribution<unsigned> numDist(3, 15);
    // This will manage the types of shapes. MaxListShape is part of Shape.hpp
    std::uniform_int_distribution<unsigned> shapeDist(0, MaxListShape);
    // This will manage what values will be part of the Shapes
    std::uniform_real_distribution<float> valDist(0.1, 100);

    uint numElements = numDist(generator);
    const AreaVisitor visitor;
    std::vector<Shape *> shapes(numElements);

    auto modifyShape = [&generator, &shapeDist, &valDist](Shape *s)
    {
        ShapeList type = ShapeList(shapeDist(generator));
        s = Shape::generateShapes(type, valDist, generator);
        return s;
    };

    std::transform(shapes.begin(), shapes.end(), shapes.begin(), modifyShape);

    auto printShape = [&visitor](Shape *shape)
    {
        std::cout << shape->acceptVisit(visitor) << std::endl;
    };

    std::for_each(shapes.begin(), shapes.end(), printShape);

    // We must deallocate all the shapes created when calling "generateShapes"
    std::for_each(shapes.begin(), shapes.end(), [](Shape *s){ delete s; } );
}

//////////////////////////////
// Main Function
//////////////////////////////
int main (int argc, const char * argv[])
{
    randomizedShapeExample();
    return 0;
}
