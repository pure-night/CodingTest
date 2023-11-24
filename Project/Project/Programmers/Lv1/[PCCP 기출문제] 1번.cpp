#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int temp = 0;

    for (int i = 0; i < attacks.size(); i++) {
        if (i > 0)
            temp = attacks[i][0] - attacks[i - 1][0] - 1;
        else
            temp = attacks[i][0] - 1;

        if (temp > 0 && answer != health) {
            answer += bandage[1] * temp;

            if (temp / bandage[0] != 0)
                answer += bandage[2] * (temp / bandage[0]);

            if (answer > health)
                answer = health;
        }
        answer -= attacks[i][1];

        if (answer <= 0)
            return -1;
    }
    return answer;
}
