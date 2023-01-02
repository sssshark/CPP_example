#include "func.h"

Bird::Bird(int size, std::string name) : birdSize(size), birdName(name) {

}

Bird::~Bird() {
    
}

std::string Bird::GetBirdName() const {
    return birdName;
}

int Bird::GetBirdSize() const  {
    return birdSize;
}