//
//  PSRStateMachine.hpp
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

#ifndef PSRStateMachine_hpp
#define PSRStateMachine_hpp

#include "PSRInterface.hpp"

// A simple struct that relates to the PSRInterface and keeps track of
// the number of players as well as the executions.
struct PSRStateMachine
{
public:
    PSRStateMachine(int playersVal = 0);
    void executeRound();
private:
    int numExecutions = 1;
    int numPlayers = 1;
    
    // Take user input and display the result. This logic could be duplicated
    // for two human players, so it is better to have it in its own function.
    PSRList requestInput();
};


#endif /* PSRStateMachine_hpp */
