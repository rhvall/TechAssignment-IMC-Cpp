//
//  PSRInterface.hpp
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

#ifndef PSRInterface_hpp
#define PSRInterface_hpp

#include <string>

// Possible outcome of the PSR game
enum ResultList
{
    player1Wins,
    player2Wins,
    drawResult
};

// Possible election the user can make (PSR)
enum PSRList
{
    paperElection,
    scissorElection,
    rockElection,
    invalidElection
};

struct PSRInterface
{
    static constexpr char *paper = (char *)"#0: 🔖 Paper";
    static constexpr char *scissors = (char *)"#1: ✂️ Scissors";
    static constexpr char *rock = (char *)"#2: 🤘Rock & roll";
    
    // This will enforce a PSRList and translate that into one of the strings above
    static const char *psrStringFromList(PSRList selection);
    
    // The first lines shown to the user
    static const std::string titleString();
    
    // A string with possible selections, compounded by the strings above
    static const std::string psrChooseString();
    
    // Check if the player input is valid and its the corresponding string
    static const std::pair<std::string, bool> selectionString(PSRList userSelection);
    
    // Transfor the ResultList to an string
    static const std::string resultString(ResultList whoWins);
    
    // NOTE!! The use of enum forces parsing of general integers to more limited values
    // within the spec, for example only allow 3 possible outcomes in the result.
    // Also, they are static functions to have them more accesible to other struct/classes,
    // they are "pure" functions and they do not depent on state from the struct.
    
    // Result matrix matches player1 vs player2 outputs.
    // #0 - Paper = P, #1 - Scissors = S, #2 - Rock = R
    // Player1 = P1, Player2 = P2
    //                                                    P             S           R
    //                                              P     D             P2          P1
    //                                              S     P1            D           P2
    //                                              R     P2            P1          D
    static constexpr ResultList resultMatrix[3][3] = {{drawResult, player2Wins, player1Wins},
                                                      {player1Wins, drawResult, player2Wins},
                                                      {player2Wins, player1Wins, drawResult}};
};

#endif /* PSRInterface_hpp */
