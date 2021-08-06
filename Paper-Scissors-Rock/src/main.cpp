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

#include "PSRStateMachine.hpp"

int main (int argc, const char * argv[])
{
    // Change the rand seed number
    srand(static_cast<unsigned int>(time(NULL)));
    
    // Default number of repetitions
    int repetitions = 3;
    
    // Check if a number was passed to via program arguments
    if (argc == 2) {
        // argv parameters passed on the console start counting from 1
        repetitions = atoi(argv[1]);
        std::cout << "The game will run for " << repetitions  << " repetitions" << std::endl;
    }
    
    PSRStateMachine psr = PSRStateMachine(1);
    
    for (int i = 0; i < repetitions; i++) {
        psr.executeRound();
    }
    
    return 0;
}
