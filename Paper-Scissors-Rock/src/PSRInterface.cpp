//
//  PSRInterface.cpp
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

#include <sstream>
#include "PSRInterface.hpp"

const char *PSRInterface::psrStringFromList(PSRList selection) {
    switch (selection) {
        case paperElection: return paper;
        case scissorElection: return scissors;
        case rockElection: return rock;
        case invalidElection:
        default: return "Invalid Option. Please, repeat";
    }
}

const std::string PSRInterface::titleString()
{
    std::ostringstream strStream;
    strStream << "====================================================" << std::endl;
    strStream << "The game of Paper 🔖, Scissors ✂️ & Rock 🤘(roll)" << std::endl;
    strStream << "====================================================" << std::endl;
    return strStream.str();
}

const std::string PSRInterface::psrChooseString()
{
    std::ostringstream strStream;
    strStream << paper << std::endl;
    strStream << scissors << std::endl;
    strStream << rock << std::endl;
    strStream << "Choose: ";
    return strStream.str();
}

const std::pair<std::string, bool> PSRInterface::selectionString(PSRList userSelection)
{
    bool validInput = true;
    std::ostringstream strStream;
    strStream << "Choosen value: ";
    
    if (userSelection >= invalidElection || userSelection < 0) {
        validInput = false;
        
    }
    
    strStream << psrStringFromList(userSelection);    
    
    return make_pair(strStream.str(), validInput);
}

const std::string PSRInterface::resultString(ResultList whoWins)
{
    std::ostringstream strStream;
    
    switch (whoWins) {
        case player1Wins:
            strStream << "Player 1 wins" << std::endl;
            break;
        case player2Wins:
            strStream << "Player 2 wins" << std::endl;
            break;
        case drawResult:
        default:
            strStream << "Draw Game" << std::endl;
            break;
    }
    
    strStream << "********************************" << std::endl;
    return strStream.str();
}
