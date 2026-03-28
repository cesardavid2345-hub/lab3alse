#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class ExamTracker {
private:
    vector<int> scores;

public:
    void addScore(int score) {
        scores.push_back(score);
    }

    double getAverage() {
        if (scores.empty()) return 0;
        return accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
    }

    int getMax() {
        int max = scores[0];
        for (int s : scores) {
            if (s > max) max = s;
        }
        return max;
    }
};

int main() {
    ExamTracker tracker;

    tracker.addScore(80);
    tracker.addScore(90);
    tracker.addScore(70);

    cout << "Promedio: " << tracker.getAverage() << endl;
    cout << "Nota máxima: " << tracker.getMax() << endl;

    return 0;
}