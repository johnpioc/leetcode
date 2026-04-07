class Robot {
private:
    int width_;
    int height_;
    pair<int, int> currentPos = { 0, 0 };
    string currentDir = "East";

    void changeDir() {
        if (this->currentDir == "East" && this->currentPos.first == this->width_ - 1) 
            this->currentDir = "North";
        else if (this->currentDir == "North" && this->currentPos.second == this->height_ -1)
            this->currentDir = "West";
        else if (this->currentDir == "West" && this->currentPos.first == 0) 
            this->currentDir = "South";
        else if (this->currentDir == "South" && this->currentPos.second == 0)
            this->currentDir = "East";
    }

    int stepsUntilEnd() {
        if (this->currentDir == "East") return this->width_ - this->currentPos.first - 1;
        else if (this->currentDir == "North") return this->height_ - this->currentPos.second - 1;
        else if (this->currentDir == "West") return this->currentPos.first;
        else return this->currentPos.second;
    }

    void move(int& remainingSteps) {
        int stepsToTake = min(remainingSteps, stepsUntilEnd());
        remainingSteps -= stepsToTake;
        int xDelta = this->currentDir == "East" ? 1 : (this->currentDir == "West" ? - 1 : 0);
        int yDelta = this->currentDir == "North" ? 1 : (this->currentDir == "South" ? -1 : 0);
        this->currentPos = { 
            currentPos.first + xDelta * stepsToTake,
            currentPos.second + yDelta * stepsToTake  
        };
    }

public:
    Robot(int width, int height): width_(width), height_(height) {}
    
    void step(int num) {
        int perimeter = 2 * width_ + 2 * (height_ - 2);
        num %= perimeter;
        if (num == 0) num = perimeter;
        while (num > 0) {
            changeDir();
            move(num);
        }
    }
    
    vector<int> getPos() {
        return { currentPos.first, currentPos.second };
    }
    
    string getDir() {
        return this->currentDir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
