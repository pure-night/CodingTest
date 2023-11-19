#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool wFind(vector<string>, vector<int>, int, char);
bool eFind(vector<string>, vector<int>, int, char);
bool sFind(vector<string>, vector<int>, int, char);
bool nFind(vector<string>, vector<int>, int, char);

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer{ -1, -1 };
    char dir;
    int dis;
    int h = park.size();
    int w = park[0].size();

    for (int i = 0; i < h; i++) {
        answer[1] = park[i].find("S");
        if (answer[1] != string::npos) {
            answer[0] = i;
            break;
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        istringstream ss(routes[i]);
        ss >> dir >> dis;

        switch (dir)
        {
        case 'W':
            if (answer[1] >= dis) {
                if (!wFind(park, answer, dis, 'X')) {
                    answer[1] -= dis;
                }
            }
            break;
        case 'E':
            if ((answer[1] + dis) < w) {
                if (!eFind(park, answer, dis, 'X')) {
                    answer[1] += dis;
                }
            }
            break;
        case 'N':
            if (answer[0] >= dis) {
                if (!nFind(park, answer, dis, 'X')) {
                    answer[0] -= dis;
                }
            }
            break;
        case 'S':
            if ((answer[0] + dis) < h) {
                if (!sFind(park, answer, dis, 'X')) {
                    answer[0] += dis;
                }
            }
        }
    }
    return answer;
}

bool wFind(vector<string> str, vector<int> off, int count, char c) {
    for (int i = 1; i <= count; i++) {
        if (str[off[0]].at(off[1] - i) == c) {
            return true;
        }
    }
    return false;
}

bool eFind(vector<string> str, vector<int> off, int count, char c) {
    for (int i = 1; i <= count; i++) {
        if (str[off[0]].at(off[1] + i) == c) {
            return true;
        }
    }
    return false;
}

bool nFind(vector<string> str, vector<int> off, int count, char c) {
    for (int i = 1; i <= count; i++) {
        if (str[off[0] - i].at(off[1]) == c) {
            return true;
        }
    }
    return false;
}

bool sFind(vector<string> str, vector<int> off, int count, char c) {
    for (int i = 1; i <= count; i++) {
        if (str[off[0] + i].at(off[1]) == c) {
            return true;
        }
    }
    return false;
}
