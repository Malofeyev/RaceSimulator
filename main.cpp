#include <iostream>
#include <Game/Game.h>

int main(int argc, char *argv[]) {
    Game game;
    Game::Response response = game.start();
    std::cout << response.message;
    
    while (!game.isTerminated()) {
        bool hasRaceType = false;
        do {
            int raceType;
            std::cin >> raceType;
            response = game.chooseRaceType(raceType);
            hasRaceType = response.result;
            std::cout << response.message;
        } while (!hasRaceType);    
        
        bool hasDistance = false; 
        do {
            double distance;
            std::cin >> distance;
            response = game.chooseDistance(distance);
            hasDistance = response.result;
            std::cout << response.message;
        } while (!hasDistance);

        bool hasOpportunityToRegistrate = true;
        bool has2Registrated = false;
        do {
            do {
                if (!has2Registrated) {
                    int one;
                    bool hasRequirement = false;
                    do {
                        std::cin >> one;
                        response = game.require2Transports(one);
                        hasRequirement = response.result;
                        std::cout << response.message;
                    } while (!hasRequirement);
                }
                bool hasExitCommand = false;
                const int exitCommand = 0;
                do {
                    int action;
                    std::cin >> action;
                    response = game.registrateTransport(action);
                    std::cout << response.message;
                    hasExitCommand = (action == exitCommand);
                } while (!hasExitCommand);
                
                has2Registrated = response.result;
            
            } while (!has2Registrated);
            
            int startRaceAction;
            const int continueRegistrateAction = 1;
            do {
                std::cin >> startRaceAction;
                response = game.startRace(startRaceAction);
                std::cout << response.message;
            } while (!response.result);

            hasOpportunityToRegistrate = (startRaceAction == continueRegistrateAction);
        } while (hasOpportunityToRegistrate);
        
        int finishAction;
        do {
            std::cin >> finishAction;
            response = game.finish(finishAction);
            std::cout << response.message;
        } while (!response.result);

    }   
    return 0;
}
