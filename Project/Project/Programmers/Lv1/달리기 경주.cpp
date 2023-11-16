#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    map<string, int> m;
    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++) {
        int rank = m[callings[i]];
        m[answer[rank - 1]]++;
        m[callings[i]]--;
        swap(answer[rank - 1], answer[rank]);
    }

    return answer;
}