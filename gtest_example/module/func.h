#include <string>

class Bird {

public:
    Bird(int size, std::string name);
    ~Bird();
    int GetBirdSize() const;
    std::string GetBirdName() const;

private:
    int birdSize;
    std::string birdName;
};