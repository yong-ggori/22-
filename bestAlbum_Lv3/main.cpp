#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool plays_cmp(pair<string, int> g1, pair<string, int> g2);

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_playsTotal;                 // 장르 별 총 플레이 횟수
    map<int, vector<pair<string, int>>> genres_plays;   // 각 고유 번호의 장르 및 플레이 횟수
    vector<pair<string, int>> playsTotal;               // 장르 별 총 플레이 횟수를 내림차순 하기 위한 벡터

    for (int idx = 0; idx < genres.size(); idx++) {
        genres_playsTotal[genres[idx]] += plays[idx];
        genres_plays[idx].push_back({ genres[idx], plays[idx] });
    }

    for(auto temp_plays : genres_plays)                 // 전체를 플레이 횟수로 내림차순 정리
        sort(temp_plays.second.begin(), temp_plays.second.end(), plays_cmp);
    
    playsTotal.assign(genres_playsTotal.begin(), genres_playsTotal.end());      // vector 함수 assign 통해 해당 값으로 대체
    sort(playsTotal.begin(), playsTotal.end(), plays_cmp);                      // 장르 별 총 플레이 횟수를 내림차순 정리

    for(int idx = 0; idx < playsTotal.size(); idx++) {
        for (int jdx = 0 ; jdx < 2;) {             // 총 2번만 실행하기 위한 반복문
            if (genres_plays[idx][jdx].first == playsTotal[idx].first) {
                answer.push_back(genres_plays);
                jdx++;
            }
        }
    }

    return answer;
}

bool plays_cmp(pair<string, int> g1, pair<string, int> g2) {
    return g1.second > g2.second;
}