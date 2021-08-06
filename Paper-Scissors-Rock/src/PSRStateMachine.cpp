//
//  PSRStateMachine.cpp
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

#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <tuple>

#include "PSRStateMachine.hpp"

PSRStateMachine::PSRStateMachine(int playersVal):
    numPlayers(playersVal)
{
}

void PSRStateMachine::executeRound()
{
    PSRList player1 = PSRList(rand() % invalidElection);
    PSRList player2 = PSRList(rand() % invalidElection);
    bool valid = false;
    
    std::string selectionStr;
    
    // Only display the title if it is the first run
    if (numExecutions == 1) {
        std::cout << PSRInterface::titleString();
    }
    
    std::cout << "Execution: " << numExecutions << std::endl;
    std::cout << PSRInterface::psrChooseString();
    
    switch (numPlayers) {
        // Only one human player
        case 1: {
            player1 = requestInput();
            std::tie(selectionStr, valid) = PSRInterface::selectionString(player2);
            std::cout << selectionStr << std::endl;
            break;
        }
        // Two human players
        case 2: {
            player1 = requestInput();
            player2 = requestInput();
            break;
        }
        // Two computer players
        default:{
            std::tie(selectionStr, valid) = PSRInterface::selectionString(player1);
            std::cout << selectionStr << std::endl;
            std::tie(selectionStr, valid) = PSRInterface::selectionString(player2);
            std::cout << selectionStr << std::endl;
            break;
        }
    }
    
    // Check the user result against the computer in the matrix
    ResultList result = PSRInterface::resultMatrix[player1][player2];
    std::cout << PSRInterface::resultString(result);
    
    numExecutions++;
}

PSRList PSRStateMachine::requestInput()
{
    bool valid = false;
    int user = 0;
    PSRList player = invalidElection;
    
    while (valid == false) {
        // Clear the buffer before asking users their input
        std::cin.clear();
        std::cin >> user;
        // Add this line to avoid crazy behavior when input is not a number
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        // If the input value is within range, it will be valid and break the loop
        player = PSRList(user);
        std::string selectionStr;
        std::tie(selectionStr, valid) = PSRInterface::selectionString(player);
        std::cout << selectionStr << std::endl;
    }
    
    return player;
}
