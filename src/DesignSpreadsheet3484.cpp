class Spreadsheet {
private:
    const int NUM_COLS = 26;
    unordered_map<string, int> cells_;
    int numRows_;

    int evaluateTerm(string term) {
        int firstCharValue = term[0] - 'A';
        if (0 <= firstCharValue && firstCharValue < this->NUM_COLS) {
            return this->cells_[term];
        }

        return stoi(term);
    }

public:
    Spreadsheet(int rows) {
        this->numRows_ = rows; 
    }
    
    void setCell(string cell, int value) {
        this->cells_[cell] = value;
    }
    
    void resetCell(string cell) {
        this->cells_.erase(cell);
    }
    
    int getValue(string formula) {
        auto it = find(formula.begin(), formula.end(), '+');
        int plusIndex = distance(formula.begin(), it);

        return evaluateTerm(formula.substr(1, plusIndex - 1)) 
            + evaluateTerm(formula.substr(plusIndex + 1));
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */